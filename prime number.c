def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

# Function to check if a number is perfect
def is_perfect(n):
    if n <= 1:
        return False
    divisors_sum = sum(i for i in range(1, n) if n % i == 0)
    return divisors_sum == n

# Function to find prime numbers in an interval
def find_primes_in_interval(start, end):
    return [num for num in range(start, end + 1) if is_prime(num)]

# Function to find perfect numbers in an interval
def find_perfects_in_interval(start, end):
    return [num for num in range(start, end + 1) if is_perfect(num)]

# Input the range
try:
    start = int(input("Enter the start of the interval: "))
    end = int(input("Enter the end of the interval: "))
    
    if start > end:
        print("Invalid range: start should be less than or equal to end.")
    else:
        # Find and display results
        prime_numbers = find_primes_in_interval(start, end)
        perfect_numbers = find_perfects_in_interval(start, end)

        print(f"Prime numbers between {start} and {end}: {prime_numbers}")
        print(f"Perfect numbers between {start} and {end}: {perfect_numbers}")
except ValueError:
    print("Please enter valid integers for the interval.")
