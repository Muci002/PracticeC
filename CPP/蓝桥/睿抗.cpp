#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int full[6] = {0, 30, 50, 60, 80, 100}; // 段位满分数组

struct Examinee 
{
    string id;
    int score;
};

// 比较函数：成绩降序，成绩相同时准考证号升序
bool cmp(const Examinee &a, const Examinee &b) 
{
    if (a.score != b.score) 
    {
        return a.score > b.score;
    }
    return a.id < b.id;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<vector<Examinee>> groups(6); // 存储1~5段位的考生
    vector<string> zeroScores; // 存储零分考生
    int bucket[101] = {0}; // 桶，记录每个分数出现的次数

    // 读取考生数据
    for (int i = 0; i < N; i++) {
        string id;
        int score;
        cin >> id >> score;
        bucket[score]++; // 更新桶计数

        if (score == 0) {
            zeroScores.push_back(id);
        } else {
            // 确定考生段位
            int level = 1;
            for (; level <= L; level++) {
                if (score <= full[level] && score > full[level-1]) {
                    break;
                }
            }
            groups[level].push_back({id, score});
        }
    }

    // 计算前缀和数组：T_value[i]表示分数不超过i的考生总人数
    int T_value[101];
    T_value[0] = bucket[0];
    for (int i = 1; i <= 100; i++) {
        T_value[i] = T_value[i-1] + bucket[i];
    }

    // 从高段位到低段位处理并输出
    for (int lev = L; lev >= 1; lev--) {
        vector<Examinee> &group = groups[lev];
        if (group.empty()) continue;

        // 段位内排序
        sort(group.begin(), group.end(), cmp);

        // 计算每个分数对应的段位内排名
        map<int, int> rankMap;
        int count = 0; // 累计人数
        int currentScore = -1;
        for (int i = 0; i < group.size(); i++) {
            if (group[i].score != currentScore) {
                currentScore = group[i].score;
                rankMap[currentScore] = count + 1; // 新分数的排名为累计人数+1
            }
            count++;
        }

        // 输出该段位考生
        for (int i = 0; i < group.size(); i++) {
            Examinee &e = group[i];
            int rankInLevel = rankMap[e.score];
            int T_val = T_value[full[lev]]; // 该段位的T值
            cout << e.id << " " << lev << " " << e.score << "/" << full[lev] << " " << rankInLevel << "/" << T_val << endl;
        }
    }

    // 输出零分考生（按字典序排序）
    sort(zeroScores.begin(), zeroScores.end());
    for (string id : zeroScores) {
        cout << id << endl;
    }

    return 0;
}