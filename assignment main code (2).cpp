#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct student {
    int id;
    string name;
    double gpa;
};

struct course {
    string code;
    string name;
    int credits;
    int val;
    string pre;
};

class datagen {
private:
    long long seed;
    long long state;

public:
    datagen(int user_seed) {
        seed = user_seed;
        state = user_seed;
    }

    long long next_random() {
        state = (1103515245LL * state + 12345LL) % 2147483648LL;
        return state;
    }

    vector<course> generate_courses() {
        int n = 12 + (seed % 6);
        vector<course> courses;

        for (int i = 0; i < n; i++) {
            course c;
            c.code = "CS" + to_string(200 + i);
            c.name = "course_" + to_string(i + 1);
            c.credits = 3;
            c.val = 6 + (next_random() % 10);
            if (i == 0) {
                c.pre = "-";
            } else {
                c.pre = "CS" + to_string(200 + (next_random() % i));
            }
            courses.push_back(c);
        }
        return courses;
    }

    vector<student> generate_students() {
        int m = 40 + (seed % 20);
        vector<student> students;

        for (int i = 0; i < m; i++) {
            student s;
            s.id = 202316154 + i;
            s.name = "student_" + to_string(i + 1);
            s.gpa = 2.0 + ((next_random() % 200) / 100.0);
            students.push_back(s);
        }
        return students;
    }

    void print_info() {
        int n = 12 + (seed % 6);
        int m = 40 + (seed % 20);
        int cap = 15 + (seed % 4);
        cout << "seed: " << seed << "\n";
        cout << "courses (n): " << n << " | records (m): " << m << " | credit cap: " << cap << "\n\n";
    }
};

class selsort {
private:
    void swap_students(student& a, student& b) {
        student temp = a;
        a = b;
        b = temp;
    }

public:
    int comparisons;
    int swaps;

    selsort() {
        comparisons = 0;
        swaps = 0;
    }

    vector<student> sort(vector<student> arr) {
        comparisons = 0;
        swaps = 0;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j].gpa < arr[min_idx].gpa) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap_students(arr[i], arr[min_idx]);
                swaps++;
            }
        }
        return arr;
    }
};

class inssort {
public:
    int comparisons;
    int shifts;

    inssort() {
        comparisons = 0;
        shifts = 0;
    }

    vector<student> sort(vector<student> arr, bool trace = false) {
        comparisons = 0;
        shifts = 0;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            student key = arr[i];
            int j = i - 1;

            while (j >= 0) {
                comparisons++;
                if (arr[j].gpa > key.gpa) {
                    arr[j + 1] = arr[j];
                    shifts++;
                    j--;
                } else {
                    break;
                }
            }
            arr[j + 1] = key;

            if (trace) {
                for (int k = 0; k < n; k++) {
                    cout << fixed << setprecision(2) << arr[k].gpa;
                    if (k == i) {
                        cout << " | ";
                    } else {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
        }
        return arr;
    }
};

int main() {
    int student_seed = 6154;
    datagen gen(student_seed);

    gen.print_info();

    vector<student> students = gen.generate_students();

    selsort sel;
    vector<student> sel_sorted = sel.sort(students);
    cout << "selection sort -> comparisons: " << sel.comparisons << ", swaps: " << sel.swaps << "\n\n";

    inssort ins;
    vector<student> ins_sorted = ins.sort(students);
    cout << "insertion sort -> comparisons: " << ins.comparisons << ", shifts: " << ins.shifts << "\n\n";

    cout << "--- trace mode (first 10 students - insertion sort) ---\n";
    vector<student> trace_sample(students.begin(), students.begin() + 10);
    ins.sort(trace_sample, true);

    return 0;
}