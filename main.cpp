#include <iostream>
using namespace std;

double ProcessExam(void);
double ProcessZybook(void);
double ProcessClassPart(void);
double ProcessHW(void);
double ProcessLW(void);
double ProcessEC(void);
double OutputGrades(double examAvg, double zybookAvg, double classPart, double hwAvg, double labAvg, double extraCredit);
void LetterGrade(double numGrade, double examAvg);
double AdjustPoints(double num);

int hwMissing;

int main() {

char syllabus_quiz;
double extraCredit;
double numGrade;
double examAvg;
double zybookAvg;
double classPart;
double hwAvg;
double labAvg;

cout << "did you get 100% on the syllabus quiz [y/n]? ";
cin >> syllabus_quiz;
if (syllabus_quiz == 'n') {
	cout << "letter grade: F";
}
else {
	examAvg = ProcessExam();
	zybookAvg = ProcessZybook();
	classPart = ProcessClassPart();
	hwAvg = ProcessHW();
	labAvg = ProcessLW();
	extraCredit = ProcessEC();
	numGrade = OutputGrades(examAvg, zybookAvg, classPart, hwAvg, labAvg, extraCredit);
	LetterGrade(numGrade, examAvg);

}
}


double ProcessExam()
{
		double examOne;
		double examTwo;
		double examFinal;
		double examAvg;
		cout << "exam 1 grade [0-100]: ";
		cin >> examOne;
		cout << "exam 2 grade [0-100]: ";
		cin >> examTwo;
		cout << "final exam grade [0-100, -1 to skip]: ";
		cin >> examFinal;
		examAvg = (examOne + examTwo + examFinal) / 3;
		if (examFinal == -1) {
			examAvg = (0.4 * examOne) + (0.6 * examTwo);
		}

		else if (examFinal >= examAvg) {
			examAvg = examFinal;

		}
		return examAvg;
}


double ProcessZybook()
{
		double zybookPart;
		double zybookChal;
		double zybookAvg;
		cout << "zybook participation (%): ";
		cin >> zybookPart;
		zybookPart = AdjustPoints(zybookPart);
		cout << "zybook challenge (%): ";
		cin >> zybookChal;
		zybookChal = AdjustPoints(zybookChal);

		zybookAvg = ((zybookPart*(4.0/7.0)) + (zybookChal*(3.0/7.0)));

		return zybookAvg;
}

double AdjustPoints(double num)
{
	if (num >= 85) {
				num = 100;
			}
			else if (num != 0) {
					num = num + 15;
				}
	return num;
}


double ProcessClassPart()
{
		double classPart;
		cout << "class participation (%): ";
		cin >> classPart;
		classPart = AdjustPoints(classPart);
		return classPart;

}


double ProcessHW()
{
		double hwTotal;
		double hwNum;
		double hwGrade;
		double hwAvg;
		hwTotal = 0;
		hwNum = 1;
		hwMissing = 0;
		do {
			cout << "homework " << hwNum << " [0-100, -1 to end]: ";
			cin >> hwGrade;
			if (hwGrade != -1) {
			hwTotal = hwTotal + hwGrade;
			hwNum = hwNum + 1;
			}
			if (hwGrade == 0) {
				hwMissing = hwMissing + 1;
			}
		}

		while (hwGrade != -1);
		if (hwNum > 1) {
			hwAvg = hwTotal / (hwNum - 1);
			}
			else {
				hwAvg = 0;
			}
			return hwAvg;
}


double ProcessLW()
{
		double labTotal;
		double labNum;
		double labGrade;
		double labAvg;
		labTotal = 0;
		labNum = 1;
		do {
			cout << "labwork " << labNum << " [0-100, -1 to end]: ";
			cin >> labGrade;
			if (labGrade != -1) {
			labTotal = labTotal + labGrade;
			labNum = labNum + 1;
			}
		}
		while (labGrade != -1);
		if (labNum > 1) {
				labAvg = labTotal / (labNum - 1);
				labAvg = AdjustPoints(labAvg);
			    }
			 else {
				   labAvg = 0;
			 }
		    return labAvg;
}


double OutputGrades(double examAvg, double zybookAvg, double classPart, double hwAvg, double labAvg, double extraCredit)
{
		  double numGrade;
	      cout << "exams: " << examAvg << endl;
		  cout << "zybook activities: " << zybookAvg << endl;
		  cout << "class participation: " << classPart << endl;
		  cout << "homework: " << hwAvg << endl;
		  cout << "labwork: " << labAvg << endl;
		  cout << "extra credit: " << extraCredit << endl << endl;
		  numGrade = ((examAvg * 0.5) + (zybookAvg * 0.07) + (classPart * 0.03) + (hwAvg * 0.35) + (labAvg * 0.05)) + extraCredit;
	      cout << "numeric grade: " << numGrade << endl;
	      return numGrade;
}


double ProcessEC()
{
		  double extraCredit;
		  cout << "extra credit points [0-1]: ";
		  cin >> extraCredit;
		  cout << endl << endl;
		  return extraCredit;
}

void LetterGrade(double numGrade, double examAvg)
{
    if (hwMissing > 2) {
    	cout << "letter grade: F";
    }

    else if (numGrade < 60) {
       	cout << "letter grade: F";
       }

    else if (examAvg < 60) {
    	cout << "letter grade: D";
    }

    else if (numGrade >= 90) {
    	cout << "letter grade: A";
    }

    else if (numGrade < 90 && numGrade > 79) {
    	cout << "letter grade: B";
    }

    else if (numGrade < 80 && numGrade > 69) {
    	cout << "letter grade: C";
    }

    else if (numGrade < 70 && numGrade > 59) {
        cout << "letter grade: D";
    }

}
