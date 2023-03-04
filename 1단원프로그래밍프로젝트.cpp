//#include <iostream>
//#include <ctime>
//
//int sumAlgorithmA(int n) {
//	int sum = n * (n + 1) / 2;
//	return sum;
//}
//
//int sumAlgorithmB(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += i;
//	}
//	return sum;
//}
//
//int sumAlgorithmC(int n) {
//	int sum = 0;
//	for (int i = 0; i <= n; i++) {
//		sum += (1 * i);
//	}
//	return sum;
//}
//
//int main() {
//	int n;
//	std::cin >> n;
//	std::cout << sumAlgorithmA(n) << std::endl; // O(n) = n^2
//	std::cout << sumAlgorithmB(n) << std::endl; // O(n) = n
//	std::cout << sumAlgorithmC(n) << std::endl; // O(n) = ?
//}