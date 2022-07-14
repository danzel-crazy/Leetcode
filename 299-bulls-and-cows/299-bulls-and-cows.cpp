class Solution {
public:
    string getHint(string secret, string guess) {
        int cows(0), bulls(0), s[10] = {0}, g[10] = {0};

	// count bulls
	for(int i = 0; i < secret.size(); i++)
		if(secret[i] == guess[i]) 
			bulls++;
		else
			s[secret[i] - '0']++, g[guess[i] - '0']++;        

	// count cows
	for(int i = 0; i < 10; i++)
		cows += min(s[i], g[i]);

	return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};