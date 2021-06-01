// Euclidean algorithm
// Find for "Greatest common divisor"

class Euclidean{

public:

	static int basic(const int& n1, const int& n2) {
		if (n2 == 0)
			return n1;
		return basic(n2, n1 % n2);
	}

};


/* References:
   1. Euclidean algorithms (Basic and Extended) :https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
   2. GCD : https://en.wikipedia.org/wiki/Greatest_common_divisor#:~:text=In%20mathematics%2C%20the%20greatest%20common,is%204%2C%20that%20is%2C%20.
   3. Java : https://www.baeldung.com/java-greatest-common-divisor
*/