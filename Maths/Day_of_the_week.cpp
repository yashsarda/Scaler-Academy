int count_leap_years(int year,int month)
{
    int c = 0;
    if(month <= 2){
        year--;
        c = (year) / 4 - year / 100 + year / 400;
        return c;
    }
    c = year / 4 - year / 100 + year / 400;
    return c;

}
string Solution::solve(int A, int B, int C) {
    string ans[7] = {"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
    int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    long long count_days = 0;
    // Total days passed from 1/1/1 AD can be calculated as
    // Days = (y - 1) * 365 + total number of days in the months before the given month + days in this month + number of leap year
    // Leap year add 1 to the count
    count_days = (C - 1) * 1ll * 365;
    for(int i=0;i<B-1;i++)
        count_days += arr[i];
    count_days += A;
    count_days += count_leap_years(C,B);
    return ans[count_days % 7];

}
