/*
  Problem Link    :   https://leetcode.com/problems/integer-to-english-words/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//	Hashmap solution
class Solution {
   public:
    void findAndReplaceAll(string & data, string toSearch, string replaceStr) {
        size_t pos = data.find(toSearch);
        while( pos != string::npos) {
            data.replace(pos, toSearch.size(), replaceStr);
            pos =data.find(toSearch, pos + replaceStr.size());
        }
    }
    
    string trim(const string &s) {
        auto start = s.begin();
        while (start != s.end() && isspace(*start)) {
            start++;
        }

        auto end = s.end();
        do {
            end--;
        } while (distance(start, end) > 0 && isspace(*end));

        return string(start, end + 1);
    }
    
    string numberToWords(int num) {
        if (!num) return "Zero";
        string ans;
        vector<string> keyword = {"Trillion", "Billion", "Million", "Thousand", ""};

		map<int, string> prefix = {
		{1, "One"},      {2, "Two"},        {3, "Three"},      {4, "Four"},
		{5, "Five"},     {6, "Six"},        {7, "Seven"},      {8, "Eight"},
		{9, "Nine"},     {10, "Ten"},       {20, "Twenty"},    {30, "Thirty"},
		{40, "Forty"},   {50, "Fifty"},     {60, "Sixty"},     {70, "Seventy"},
		{80, "Eighty"},  {90, "Ninety"},    {100 , "Hundred"}, {11, "Eleven"},
		{12, "Twelve"},  {13, "Thirteen"},  {14, "Fourteen"},  {15, "Fifteen"},
		{16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},  {19, "Nineteen"},
		{0, ""}};

        while (num > 0) {
            string newans;
            int newnum = num % 1000;
            num /= 1000;
            int units = newnum % 10;
            newnum /= 10;
            int tens = newnum % 10;
            newnum /= 10;
            int hundreds = newnum % 10;
            if (hundreds != 0) {
                newans += prefix[hundreds] + " Hundred";
            }
            if (tens == 1) {
                newans += " " + prefix[10 + units];
            } else {
                newans += " " + prefix[10 * tens] + " " + prefix[units];
            }
            
            if(trim(newans)=="") { keyword.pop_back(); continue;}
            string key=keyword[keyword.size()-1];
            keyword.pop_back();
            ans = trim(newans) + " " + key + " " + trim(ans);
        }
        findAndReplaceAll(ans,"  "," ");
        return trim(ans);
    }
};