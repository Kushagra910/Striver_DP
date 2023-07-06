// Graph and Vertices GFG

// Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) 
// can be constructed out of a given n number of vertices.


// This formula works because for each pair of vertices, there are two possible choices: either include the edge between them or do not include it.
// Since there are n*(n-1)/2 pairs of vertices in an undirected graph, the total number of possible graphs is 2^(n*(n-1)/2).

class Solution {
  public:
    long long count(int n) {
        // your code here
        return 1LL<<(n*(n-1)/2);
    }
};