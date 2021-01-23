#include<iostream>
#include<cmath>
#include<stack>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;
bool isNumber(string line);
void evolutePostfixExpr(string,ostream&);

int operation(int , int , string);

int main()
{
   ifstream inFile;
   ofstream outFile;
   string filename;
   string expression;
   
   int choice;
   cout << "Enter the file name: ";
   cin >> filename;
   inFile.open(filename);

   cout << "\n1. Ouput on console." << endl;
   cout << "2. Ouput on file." << endl<<"Your choice: ";
   cin >> choice;

   if (choice == 2)
   {
       cout << "\nEnter the output file name: ";
       cin >> filename;
       outFile.open(filename);
       cout << "\nWrite to " << filename << endl;
   }

   while (!inFile.eof())
   {
      
       getline(inFile, expression);
       if (choice == 2)
           evolutePostfixExpr(expression,outFile);
       else
           evolutePostfixExpr(expression, cout);
      
   }
   return 1;
}

void evolutePostfixExpr(string expr,ostream &out)
{
   stack<int> stk;
   string value,errorMsg;
   bool invalid = false;
   stringstream ss(expr);
   int ans = 0;
   int a, b;
   while (ss >> value)
   {
       if (isNumber(value))
           stk.push(stoi(value));
       else if (value == "+" || value == "-" || value == "*" || value == "/")
       {
           if (stk.empty() || stk.size() == 1)
           {
               invalid = true;
               errorMsg = "To many operators";
               break;
           }
          
           a = stk.top();
           stk.pop();
           b = stk.top();
           stk.pop();
           ans = operation(a, b, value);
           stk.push(ans);
       }
       else
       {
           invalid = true;
           errorMsg = "Illegal Operation";
           break;
       }
   }
   if (invalid)
   {
       out.width(30); out << left << expr;
       out << errorMsg << endl;
       return;
   }
   if (stk.size() > 1)
   {
       invalid = true;
       errorMsg = "To few operators.";
   }
   if (invalid)
   {
       out.width(30); out << left << expr;
       out << errorMsg << endl;
       return;
   }
   else
   {
       out.width(30); out << left << expr;
       out << errorMsg << stk.top()<< endl;
   }
}

bool isNumber(string s) {
   if (s.size() == 0) return false;
   for (int i = 0; i<s.size(); i++) {
       if ((s[i] >= '0' && s[i] <= '9') == false) {
           return false;
       }
   }
   return true;
}
int operation(int a, int b, string op) {
   //Perform operation
   if (op == "+")
       return b + a;
   else if (op == "-")
       return b - a;
   else if (op == "*")
       return b * a;
   else if (op == "/")
       return b / a;
   return 0;
}