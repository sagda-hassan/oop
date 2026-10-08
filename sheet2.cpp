#include <iostream>
#include <iomanip>

using namespace std;

class Data {
private:
    float D[30];
    char T[30]; // مصفوفة لتخزين 'Y' أو 'N'
    int n;

public:
    // دالة لحساب المضروب (Factorial)
    long long factorial(int num) {
        if (num < 0) return 0;
        long long fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }

    // دالة للتحقق هل الرقم أولي أم لا (Prime Test)
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // دالة قراءة البيانات وتحديد قيم T
    void readData() {
        cout << "Enter number of elements (n <= 30): ";
        cin >> n;
        cout << "Enter " << n << " positive integer elements for array D:\n";
        for (int i = 0; i < n; i++) {
            cout << "D[" << i << "]: ";
            cin >> D[i];
            
            // تحويل الرقم لعدد صحيح للتحقق من كونه أولي
            int val = (int)D[i];
            if (isPrime(val)) {
                T[i] = 'Y';
            } else {
                T[i] = 'N';
            }
        }
    }

    // دالة حساب مجموع مضروب الأرقام الأولية
    long long sumFactorialPrime() {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (T[i] == 'Y') {
                sum += factorial((int)D[i]);
            }
        }
        return sum;
    }

    // دالة حساب حاصل ضرب مضروب الأرقام غير الأولية (بشرط ألا تساوي 0)
    long long productFactorialNonPrime() {
        long long prod = 1;
        bool hasNonPrime = false;
        for (int i = 0; i < n; i++) {
            if (T[i] == 'N' && (int)D[i] != 0) {
                prod *= factorial((int)D[i]);
                hasNonPrime = true;
            }
        }
        return hasNonPrime ? prod : 0;
    }

    // دالة عرض البيانات في جدول
    void displayTable() {
        cout << "\n-----------------------------\n";
        cout << setw(10) << "Index" << setw(10) << "D[i]" << setw(10) << "Is Prime(T)" << "\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << setw(10) << i << setw(10) << D[i] << setw(10) << T[i] << "\n";
        }
        cout << "-----------------------------\n";
    }
};

int main() {
    Data obj;
    
    // استدعاء كافة الدوال
    obj.readData();
    obj.displayTable();
    
    cout << "Sum of factorials of prime numbers: " << obj.sumFactorialPrime() << endl;
    cout << "Product of factorials of non-prime numbers (!= 0): " << obj.productFactorialNonPrime() << endl;

    return 0;
}