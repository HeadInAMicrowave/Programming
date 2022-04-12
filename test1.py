# Function to calculate the greatest common divisor
from functools import reduce
import doctest
from math import floor


def extended_euclidean_algorithm(a, b):
    """
    Calculates gcd(a,b) and a linear combination such that gcd(a,b) = a*x + b*y
    """

    a0, b0 = a, b

    x = lasty = 0
    y = lastx = 1
    while b != 0:
        q = a / b
        a, b = b, a % b
        x, lastx = lastx - q * x, x
        y, lasty = lasty - q * y, y
    return {"remainder": a, "x": lastx, "y": lasty, "gcd": a0 * lastx + b0 * lasty}


def is_coprime(x, y):
    """Function to check if two numbers are coprime"""
    return extended_euclidean_algorithm(x, y)["remainder"] == 1


def phi_func(x):
    """
    Function that calculates the Euler's Phi function of a given number (counts all the prime numbers in range from 1
    to the given number x)
    """
    if x == 1:
        return 1
    else:
        n = [y for y in range(1, x) if is_coprime(x, y)]
        return len(n)


def rns(a, b):
    """Function that calculates a number, given its notation in RNS (a) plus the set of moduli (b)"""

    val = 1
    i = 0
    while i < len(a):
        if val % b[i] == a[i]:
            i += 1
        else:
            val += 1
    return val


def sum_up(a, b, m):
    """Converts two numbers (a, b) in RNS notation with given moduli (m) to regular integers and sums them up"""

    temp1 = rns(a, m)
    temp2 = rns(b, m)
    result = temp1 + temp2
    return result


def prod(a, b, m):
    """Converts two numbers (a, b) in RNS notation with given moduli (m) to regular integers and multiplies them"""

    temp1 = rns(a, m)
    temp2 = rns(b, m)
    result = temp1 * temp2
    return result


def cong_solve(a, b, m):
    """Solves a singular congruence with a form of aX ≡ b (mod m)"""

    if b == 0:
        return 0

    if a < 0:
        a = -a
        b = -b

    b %= m
    while a > m:
        a -= m

    return (m * cong_solve(m, -b, a) + b) // a


def set_cong_solve(rests, moduli):
    """
    Solve a system of linear congruences.
    """
    assert len(rests) == len(moduli)
    x = 0
    M = reduce(lambda x, y: x * y, moduli)

    for mi, resti in zip(moduli, rests):
        Mi = M / mi
        s = extended_euclidean_algorithm(Mi, mi)["x"]
        e = s * Mi
        x += resti * e
    return {"congruence class": ((x % M) + M) % M, "modulo": M}


if __name__ == "__main__":
    Euler_Phi = 33  # Value that we calculate the phi_func; used for solving problems 17 and 18
    #  Variables for problem 34
    RNS_known1 = [3, 4, 5]  # a number represented in rns notation
    RNS_known2 = [2, 1, 8]  # another number represented in rns notation
    RNS_moduli = [5, 7, 11]  # moduli for the rns() function
    # Variables for problems from 11 to 16
    rests_cong = [1, 2, 3]  # integers used in the set of congruences
    moduli_cong = [7, 5, 11]  # remainders used in the set of congruences

    # prints result of phi_func for given  Euler_Phi parameter
    print("Euler function for given parameters: " + str(phi_func(Euler_Phi)))

    # prints the result of the rns() function for given parameters RNS_known1 and rns_moduli
    print("RNS-to-normal conversion result: " + str(rns(RNS_known1, RNS_moduli)))

    print("RNS-to-normal conversion result: " + str(rns(RNS_known2, RNS_moduli)))  # same as above

    # prints the result of prod and sumup in the terminal
    print("Sum of the numbers is: " + str(sum_up(RNS_known1, RNS_known2, RNS_moduli)))
    print("Product of the numbers is: " + str(prod(RNS_known1, RNS_known2, RNS_moduli)))

    # prints result for the given set of congruences; Problems from 11 to 16
    print("Result for the set of congruences: " + str(floor(set_cong_solve(rests_cong, moduli_cong)["congruence class"])
                                                      ))
