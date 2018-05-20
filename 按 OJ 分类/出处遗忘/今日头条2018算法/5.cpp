#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3003;

struct idea
{
    int PM_id;              //  PM 序号
    int post_time;          //  提出时间
    int priority;           //  优先权
    int cost_time;          //  所需时间
    int order;              //  idea 序号
} ideas[MAXN];

int N, M, P;                //  N PM, M Program, P idea
int finish_time[MAXN];      //  完成每个 idea 时间
int program_time[MAXN];     //  程序猿空闲时刻
vector<idea> PM_idea[MAXN]; //  每个 PM 在某时刻所拥有的未完成 idea

//  按照提出时间从小到达排序
bool cmp_post(const idea &a, const idea &b)
{
    return a.post_time < b.post_time;
}

//  按照第一关键词优先级从大到小，第二关键词花费时间从小到大，第三关键词提出时间从小到大排序
bool cmp_priority(const idea &a, const idea &b)
{
    if (a.priority != b.priority)
    {
        return a.priority > b.priority;
    }
    else
    {
        if (a.cost_time != b.cost_time)
        {
            return a.cost_time < b.cost_time;
        }
        return a.post_time < b.post_time;
    }
}

//  按照第一关键词花费时间从小到大，第二关键词 PM 序号从小到大排序
bool cmp_cost(const idea &a, const idea &b)
{
    if (a.cost_time != b.cost_time)
    {
        return a.cost_time < b.cost_time;
    }
    return a.PM_id < b.PM_id;
}

int main()
{
    scanf("%d%d%d", &N, &M, &P);
    
    int a, b, c, d;
    for (int i = 0; i < P; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ideas[i] = {a - 1, b, c, d, i};
    }
    sort(ideas, ideas + P, cmp_post);     //   按照 cmp_post 排序，为后续给 PM 添加 idea
    
    int now_time = 1, cnt = 0, last = 0;  //   now_time 现在时刻，cnt 已经完成任务，last 下一次添加任务起点
    while (cnt < P)
    {
        for (int i = last; i < P; i++)
        {
            if (ideas[i].post_time == now_time)
            {
                //  给 PM 添加 idea 并且按照 cmp_priority 排序，为后续生成每个 PM 最想完成 idea
                PM_idea[ideas[i].PM_id].push_back(ideas[i]);
                sort(PM_idea[ideas[i].PM_id].begin(), PM_idea[ideas[i].PM_id].end(), cmp_priority);
                
                if (i == P - 1)
                {
                    last = P;
                }
            }
            else
            {
                last = i;
                break;
            }
        }
        
        //  选取每个 PM 最想完成的 idea
        vector<idea> PM_priority;
        for (int i = 0; i < N; i++)
        {
            if (!PM_idea[i].empty())
            {
                PM_priority.push_back(PM_idea[i][0]);
            }
        }
        
        for (int i = 0; i < M; i++)
        {
            //  程序猿空闲并且此刻有 idea 可供选择
            if (program_time[i] <= now_time && !PM_priority.empty())
            {
                //  按照 cmp_cost 排序，为后续给程序猿选取 idea
                sort(PM_priority.begin(), PM_priority.end(), cmp_cost);
                //  选取 idea 并且更新程序猿空闲时间和存储该 idea 完成时间
                program_time[i] = now_time + PM_priority[0].cost_time;
                finish_time[PM_priority[0].order] = program_time[i];
                //  从 PM 此刻 idea 中删除已经选取的 idea
                PM_idea[PM_priority[0].PM_id].erase(PM_idea[PM_priority[0].PM_id].begin());
                //  如果该 PM 依然有 idea，则将下一个 idea 添加到 PM 最想完成 idea 集合中
                if (!PM_idea[PM_priority[0].PM_id].empty())
                {
                    PM_priority.push_back(PM_idea[PM_priority[0].PM_id][0]);
                }
                //  从 PM 最想完成 idea 集合中删除已经选取过的 idea
                PM_priority.erase(PM_priority.begin());
                cnt++;                                 //  完成 idea 数自增
            }
        }
        
        now_time++;                                    //  现在时间自增
    }
    
    for (int i = 0; i < P; i++)
    {
        printf("%d\n", finish_time[i]);
    }
    
    return 0;
}
