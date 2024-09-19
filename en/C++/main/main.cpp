#include "question/81_Search_in_Rotated_Sorted_Array_II.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1,1,1,13,1,1,1,1,1]\",\"13\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      int arg1 = parseInteger(args[1]);
      bool result=s->search(arg0,arg1);
      string resultabc =serializeBool(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}