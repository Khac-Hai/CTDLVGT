#include <iostream>
#include <vector>

std::vector<double> SumPoly(const std::vector<double>& poly1, const std::vector<double>& poly2) {
int size1 = poly1.size();
int size2 = poly2.size();
int resultsize = std::max(size1, size2);
std::vector<double> result(resultsize);
for (int i = 0; i < size1; i++) {
    result[i] += poly1[i];
}
for (int i = 0; i < size2; i++) {
    result[i] += poly2[i];
}
    return result;
}

std::vector<double> MultiplyPoly(const std::vector<double>& poly1, const std::vector<double>& poly2) {
int size1 = poly1.size();
int size2 = poly2.size();
int resultsize = size1 + size2 - 1;
std::vector<double> result(resultsize);
for (int i = 0; i < size1; i++) {
    for (int j = 0; j < size2; j++) {
        result[i + j] += poly1[i] * poly2[j];
    }
}
    return result;
}

void pretty_print(const std::vector<double>& poly) {
int size = poly.size();
for (int i = size - 1; i >= 0; i--) {
    if (poly[i] != 0) {
        if (i == size - 1) {
            std::cout << poly[i] << "x^" << i;
        } else if (i == 0) {
            std::cout << " + " << poly[i];
            } else {
                std::cout << " + " << poly[i] << "x^" << i;
            }
    }
}
std::cout << std::endl;
}

int main(){
    std::vector<double> poly1 = {2, 3, -12, 2, 0, 0, 4};
    std::vector<double> poly2 = {2, -3, 12};
    std::vector<double> sum = SumPoly(poly1, poly2);
    std::vector<double> multi = MultiplyPoly(poly1, poly2);
    std::cout << "Sum: ";
    pretty_print(sum);
    std::cout << "Multi: ";
    pretty_print(multi);
    return 0;
}