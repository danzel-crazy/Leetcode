class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> result;
        
        for(auto path : paths){
            stringstream ss(path);
            string s;
            string root;
            getline(ss, root, ' ');
            while(getline(ss, s, ' ')){
                string file_name = root + '/' + s.substr(0, s.find('('));
                string file_content = s.substr(s.find('(')+1, s.find(')')-s.find('(')-1);
                files[file_content].push_back(file_name);
            }
        }
        
        for(auto i : files){
            if(i.second.size() > 1)
                result.push_back(i.second);
        }
        
        return result;
    }
};