class Solution {
private:
    void _dfs(unordered_set<string>& merged_account, vector<vector<string>>& accounts, unordered_map<string, vector<int>>& email_to_account_ids, vector<bool>& visited, int id) {
        visited[id] = true;
        vector<string> cur = accounts[id];
        for (int i = 1; i < accounts[id].size(); i++) {
            merged_account.insert(accounts[id][i]);
            for (const int& nextid : email_to_account_ids[accounts[id][i]]) {
                if (!visited[nextid]) {
                    _dfs(merged_account, accounts, email_to_account_ids, visited, nextid);
                }
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> email_to_account_ids;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                email_to_account_ids[accounts[i][j]].push_back(i);
            }
        }
        
        vector<vector<string>> merged_accounts;
        vector<bool> visited (accounts.size(), false);
        for (int i = 0; i < accounts.size(); i++) {
            if (!visited[i]) {
                unordered_set<string> merged_account;
                _dfs(merged_account, accounts, email_to_account_ids, visited, i);
                vector<string> merged_account_vec {accounts[i][0]};
                merged_account_vec.insert(merged_account_vec.end(), merged_account.begin(), merged_account.end());
                sort(merged_account_vec.begin() + 1, merged_account_vec.end());
                merged_accounts.push_back(merged_account_vec);
            }
        }
        return merged_accounts;
    }
};


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
