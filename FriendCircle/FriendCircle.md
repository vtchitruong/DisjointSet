Initially, none of the people are friends with each other.  
In order to start a friendship, two persons a and b have to shake hands.  
The friendship relation is transitive, that is if a and b shake hands with each other, a and friends of a become friends with b and friends of b.  
  
You will be given n queries.  
After each query, you need to report the size of the largest friend circle (the largest group of friends) formed after considering that query.  

### Constraints
1 <= n <= 10^5 (number of queries)  
1 <= query[i][0], query[i][1] <= 10^9  

### Sample Input
2  
1 2  
1 3  

### Sample Output
2  
3  

### Explanation
In the first query, 1 and 2 shake hands. So, the size of largest group of friends is 2 (as no other friendships exist).  
After the second query, 1, 2 and 3 all become friends, as 1 shakes hand with 3, 2 also become friends with 3 as he was already a friend of 1.  

### Source
The problem could be found at [HackerRank](https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous).