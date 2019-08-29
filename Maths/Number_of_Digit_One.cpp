// This is a really tricky. Look at it again

// Understand the formula
/*
    one's place: 1  11  21  31  41  51  61  71  81  91  ...
    After every group of 10 we have one 1 appearing at the unit's place

    ten's place: 10     110     210     ....
                 11     111     211     ....
                 12     112     212     ....
                 13     113     213     ....
                 14     114     214     ....
                 15     115     215     ....
                 16     116     216     ....
                 17     117     217     ....
                 18     118     218     ....
                 19     119     219     ....
    After every group of 100 we have 10 1's appearing at the tens place

    For eg: If A = 215
    Last number with 1 at the unit's place = 211
    Number of 1's at one's place = (215 / 10) * 1;
    It denotes that after every group of 10 we have one 1.
    It will include (1,11,21,31......201), now 211 remained and it will only we added if (n % 10 != 0).
    Why ? Because if (n % 10 == 0) (For eg: 210.all the number which are less than it are already added so need to add extra 1)
    But if n%10 != 0 then we need add one extra one for greater number.

    Consider another number A = 1234
    Last number with 1 at the tens place = 1219
    Number of 1's at ten's place = (1234 / 100) * 10;
    It denotes that after evry group of 100 we have 10 1's.
    It will include ([10...19],[110....119],[210....219].......[1110,1119]).ie. 12 complete chunks of groups of 10(1234/100 = 12)
    Plus we need to add all of[1210,1211,1212,....1219].All of the numbers in [1210,1211,...1219] are less than 1234, then why
    did we not consider 13 chunks completely. The reason is if number would have been 1211, then also 1211 / 100 = 12 and if
    we would have take value of ceil if this it would result in incorrect number of 1's. Hence we add the last chunk
    later.
    For every number of the form ab1x, there are x + 1 1's uptil this point from ab10. Hence we need to add
    max((n % 100 - 10 + 1),0).  It takes the last 2 digits and subtracts 10 from it to find the number of ones we need to add.
    Now the number of ones should be greater than 0 and less than 10.
    Hence min(max(n % 100 - 10 + 1),0),10).

    Similarly we can extend idea to include 1000's place also.
*/
int Solution::solve(int A) {
    int ans = 0;
    for(int i=1;i<=A;i*=10){
        int cal = (A / (10 * i)) * i;
        cal += min(max(A % (10*i) - i + 1,0),i);

        ans += cal;
    }

    return ans;
}
