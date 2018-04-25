/*

tt : total number of trees
n  : number of nodes




*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout;
    ifstream infile;

    int tt =7741, n = 15;    //change
    infile.open("mytree15.txt");   //change
  // fout.open("trial.csv"); int pp =2 , qq = 9;      //change
   
     //fout.open("n15r5-6.csv"); int pp =5 , qq = 6;      //change
      //fout.open("n15r5-7.csv"); int pp =5 , qq = 7;      //change  
      // fout.open("n15r5-8.csv");  int pp =5 , qq = 8;      //change
         // fout.open("n15r5-9.csv");   int pp =5 , qq = 9;      //change
           // fout.open("n15r5-11.csv");   int pp =5 , qq = 11;      //change
             //fout.open("n15r5-12.csv");     int pp =5 , qq = 12;      //change
              // fout.open("n15r5-13.csv");      int pp =5 , qq = 13;      //change
               //fout.open("n15r5-14.csv");      int pp =5 , qq = 14;      //change
    
    
   //fout.open("n15r6-7.csv");int pp =6 , qq= 7;      //change
      //fout.open("n15r6-9.csv");int pp =6 , qq = 9;      //change  
    //fout.open("n15r6-13.csv");int pp =6 , qq = 13;      //change
          // fout.open("n15r6-17.csv"); int pp =6 , qq = 17;      //change
             //fout.open("n15r6-19.csv"); int pp =6 , qq = 19;      //change
    
    // //change
   //fout.open("n15r7-8.csv"); int pp =7 , qq = 8;      //change
   //fout.open("n15r7-9.csv"); int pp =7 , qq = 9;      //change  
        // fout.open("n15r7-10.csv"); int pp =7 , qq = 10;      //change
          //  fout.open("n15r7-13.csv");  int pp =7 , qq = 13;      //change
                //fout.open("n15r7-11.csv"); int pp =7 , qq = 11;      //change
                  //fout.open("n15r7-12.csv");  int pp =7 , qq = 12;      //change
                      
     // fout.open("n15r8-9.csv");  int pp =8 , qq = 9;      //change
  //fout.open("n15r8-11.csv"); int pp =8 , qq = 11;      //change  
//fout.open("n15r8-13.csv");     int pp =8 , qq = 13;      //change
            
    // fout.open("n15r9-10.csv");  int pp =9 , qq = 10;      //change
       // fout.open("n15r9-11.csv");  int pp =9 , qq = 11;      //change  
         //  fout.open("n15r9-13.csv");  int pp =9 , qq = 13;      //change
           // fout.open("n15r9-14.csv");  int pp =9 , qq = 14;      //change
             // fout.open("n15r9-16.csv");   int pp =9 , qq = 16;      //change
              //  fout.open("n15r9-17.csv");  int pp =9 , qq = 17;      //change
                //fout.open("n15r9-19.csv");      int pp =9 , qq = 19;      //change
                 

    /* total number of trees :  
                                0		1
                                1		1
                                2		1
                                3		1
                                4		2
                                5		3       
                                6		6
                                7		11
                                8		23
                                9		47
                                10		106
                                11		235
                                12		551
                                13		1301
                                14		3159
                                15		7741
                                16		19320
                                17		48629
                                18		123867
                                19		317955
                                20		823065

*/

    //change name
    int z = 0;
    int sum1 = 0;
    while (z < tt) {

        int j = 0;
        int cen = 0; //change n
        vector<int> adj_list[30];
        vector<int> visited(n + 1, 0);
        vector<int> visited1(n + 1, 0);
        vector<int> visited2(n + 1, 0);

        int c1 = 0, c2 = 0, r = 0;

        string STRING;

        while (j < n - 1) // To get you all the lines.
        {
            getline(infile, STRING, '('); // Saves the line in STRING.

            getline(infile, STRING, ')');

            size_t pos = STRING.find(',');

            string str1 = STRING.substr(0, pos);

            string str2 = STRING.substr(pos + 2);
            int a, b;
            stringstream(str1) >> a;
            stringstream(str2) >> b;

            adj_list[a].push_back(b);

            adj_list[b].push_back(a);

            //cout<<p<<" "<<q<<endl;

            j++;
        }

        for (int i = 0; i < n; i++) {

            visited[i] = 0;
        }

        queue<int> q;

        q.push(0);
        int cur = 0;

        visited[cur] = 1;

        while (!q.empty())

        {

            cur = q.front();
            q.pop();

            for (int i = 0; i < adj_list[cur].size(); i++) {

                if (!visited[adj_list[cur][i]])

                {

                    q.push(adj_list[cur][i]);

                    visited[adj_list[cur][i]] = 1;
                }
            }
        }

        queue<int> q1;
        q.push(cur);

        visited1[cur] = 1;
        int dis[30], p[30];
        dis[cur] = 0, p[cur] = -1;
        while (!q.empty())

        {

            cur = q.front();
            q.pop();

            for (int i = 0; i < adj_list[cur].size(); i++)

            {

                if (!visited1[adj_list[cur][i]])

                {

                    q.push(adj_list[cur][i]);
                    p[adj_list[cur][i]] = cur;
                    dis[adj_list[cur][i]] = dis[cur] + 1;
                    visited1[adj_list[cur][i]] = 1;
                }
            }
        }

        int m = dis[cur];

        if (m % 2 == 0) {
            r = m / 2;
            int i = 0;
            while (i == 0) {
                if (dis[cur] == r) {
                    c1 = cur;
                    break;
                }
                else {
                    cur = p[cur];
                    if (cur == -1)
                        i = 0;
                }
            }

            c2 = -1;
        }

        else {
            r = (m + 1) / 2;
            int i = 0;
            while (i == 0) {
                if (dis[cur] == r) {
                    c1 = cur;
                    break;
                }
                else {
                    cur = p[cur];
                    if (cur == -1)
                        i = 0;
                }
            }

            c1 = cur;
            c2 = p[cur];

            for (int i = 0; i < adj_list[c2].size(); i++)

            {

                if (adj_list[c2][i] != c1) {
                    int k = adj_list[c2][i];
                    adj_list[c1].push_back(k);
                    adj_list[k].erase(remove(adj_list[k].begin(), adj_list[k].end(), c2), adj_list[k].end());
                    adj_list[k].push_back(c1);
                }
            }

            adj_list[c1].erase(remove(adj_list[c1].begin(), adj_list[c1].end(), c2), adj_list[c1].end());
        }
        cen = 0;

        queue<int> qr;
        cur = cen;
        qr.push(cur);

        int e = 0, l = 0, g = 0;
        visited2[cur] = 1;
        int dis1[30], cc[30], maxc[30], proot[30],  pr = adj_list[cur][0], maxcount=0, level = 1;

        for (int i = 0; i < n; i++) {

            cc[i] = 0;
            dis1[i] = 0;
            maxc[i] = 0;
        }
        dis1[cur] = 0, cc[cur] = 0, proot[cur] = -1 ;
        while (!qr.empty())

        {
               
            cur = qr.front();
            
            qr.pop();
            if (dis1[cur] == 0) {
                cc[dis1[cur]] += adj_list[cur].size();
               
                    maxc[dis1[cur]] = 0;
            }
            else {      
                cc[dis1[cur]] += adj_list[cur].size() - 1;
               
                         if (proot[cur] == pr && dis1[cur] == level)
                         {  maxcount += adj_list[cur].size() - 1;
                         
                         }
                         else{  
                               
                                 if (maxcount > maxc[level])
                                 maxc[level] = maxcount;
                                pr = proot[cur];
                                maxcount = adj_list[cur].size() - 1;
                                if( dis1[cur] != level)
                                        level++;
                         }
                         
                         
                        
                
            }

            

            for (int i = 0; i < adj_list[cur].size(); i++)

            {

                if (!visited2[adj_list[cur][i]])

                {
                        if (dis1[cur] == 0) {

                        
                        proot[adj_list[cur][i]] = adj_list[cur][i];
                    }
                    qr.push(adj_list[cur][i]);

                    dis1[adj_list[cur][i]] = dis1[cur] + 1;
                    if (dis1[cur] == 1) {

                        proot[adj_list[cur][i]] = cur;
                    }
                    else if (dis1[cur] > 1)
                        proot[adj_list[cur][i]] = proot[cur];
                    visited2[adj_list[cur][i]] = 1;
                }
            }
        }

        for (int i = 1; i < dis1[cur]; i++) {
            //cout << i << endl;
            //cout << cc[i] << endl;
            //cout << maxc[i] << endl
              //   << endl;

            float nd, pq;

            pq = float(pp) / float(qq);
            nd = float(maxc[i]) / float(cc[i]);
            // cout<<pq<<endl;
            // cout<<nd<<endl;

            if (nd == pq) {
                e++;
            }
            if (nd > pq)
                g++;
            if (nd < pq)
                l++;
        }
       

        //cout<<e<<" "<<l<<" "<<g<<endl;

       if((dis1[cur]>1))
{
if(e==dis1[cur]-1&&e>0&&dis1[cur]>1){
fout<<1<<",";
sum1=sum1+1;
}
else
  fout<<0<<",";
if(g==0)

fout<<1<<",";
else
  fout<<0<<",";
if(g==0&&e==0&&l>0)

fout<<1<<",";
else
  fout<<0<<",";
if(l==0)

fout<<1<<",";
else
  fout<<0<<",";

if(l==0&&g>0&&e==0)

fout<<1<<","<<endl;
else
  fout<<0<<endl;

 }
 
 else
 {
 fout<<0<<","<<0<<","<<0<<","<<0<<","<<0<<endl;
 
 }

        z++;
    }

    fout.close();
    infile.close();
    return 0;
}

