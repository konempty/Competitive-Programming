const int MAX_PRIME = 10000 +2;

// find prime
bool not_prime[MAX_PRIME];

void find_prime() {
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i <= MAX_PRIME; i++) {
		if (not_prime[i])
			continue;
		for (int j = i * 2; j <= MAX_PRIME; j += i) {
			not_prime[j] = true;
		}
	}
}

// get gcd
int get_gcd(int a, int b) {
    int mod;
    while ((mod = a%b) > 0) {
        a = b;
        b = mod;
    }
    return b;
}

