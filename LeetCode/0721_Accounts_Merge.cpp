class Solution {
private:
    void _merge_account(unordered_set<string>& merged_emails,
                        vector<vector<string>>& accounts,
                        unordered_map<string, vector<int>>& email_accountid_map,
                        vector<bool>& account_merged,
                        int i) {
        account_merged[i] = true;
        int account_size = accounts[i].size();
        for (int j = 1; j != account_size; j ++) {
            merged_emails.insert(accounts[i][j]);
            for (const int accountid : email_accountid_map[accounts[i][j]]) {
                if (account_merged[accountid]) {
                    continue;
                }
                _merge_account(merged_emails, accounts, email_accountid_map, account_merged, accountid);
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> email_accountid_map;
        int accounts_count = accounts.size();
        for (int i = 0; i != accounts_count; i++) {
            int account_size = accounts[i].size();
            for (int j = 1; j != account_size; j++) {
                if (email_accountid_map.find(accounts[i][j]) != email_accountid_map.end()) {
                    email_accountid_map[accounts[i][j]].push_back(i);
                } else {
                    email_accountid_map[accounts[i][j]] = {i};
                }
            }
        }
        
        vector<bool> account_merged(accounts_count, false);
        vector<vector<string>> res;
        for (int i = 0; i != accounts_count; i++) {
            if (account_merged[i]) {
                continue;
            }
            unordered_set<string> merged_emails;
            _merge_account(merged_emails, accounts, email_accountid_map, account_merged, i);
            vector<string> merged_emails_vec { accounts[i][0] };
            merged_emails_vec.insert(merged_emails_vec.end(), merged_emails.begin(), merged_emails.end());
            sort(merged_emails_vec.begin() + 1, merged_emails_vec.end());
            res.push_back(merged_emails_vec);
        }
        return res;
    }
};
