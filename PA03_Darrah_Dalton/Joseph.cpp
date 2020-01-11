#include <iostream>
#include <list>
#include <locale>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

template <typename ItemType>

class OurStack
{
private:
  Stack <ItemType> *OurStack;
public:

  bool isEmpty()
  {
    return OurStack->isEmpty();
  }

  bool pop()
  {
    if(!OurStack->isEmpty())
    {
      OurStack->pop();
      return true;
    }
    else
    {
      return false;
    }
  }

  bool push(const ItemType& val)
  {
    OurStack->push(val);
    if(OurStack->peek()==val)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  ItemType peek()
  {
    return OurStack->peek();
  }

};







class readin
{
  int city;

  ifstream cityfile;
  ifstream flightfile;
  ifstream requestfile;

  string flights[20][4];
  int num;
public:
    readin(char* c, char* f, char* r)
    {
      cityfile.open(c);
      flightfile.open(f);
      requestfile.open(r);
      num=0;
    }

    string getName()
    {
      string line;
      if(getline(cityfile,line))
      {
        return line;
      }
      else
      {
        return "fin";
      }
    }

    pair <string,string> getNamePair()
    {
      string line;
      string delimiter = ",";
      pair <string,string> edge;
      string space= " ";
      edge.first="stop";
      edge.second="stop";
      size_t pos =0;
      if(getline(flightfile,line))
      {
        pos=line.find(delimiter);
        edge.first=line.substr(0,pos);
        int pos1=0;
        for(int i=0;i;i++)
        {
          if(isdigit(line[i]))
          {
            pos1=i;
            break;
          }
        }
        edge.second=line.substr(pos+2,pos1-(pos+3));
        return edge;
      }
    }

    pair <string,string> getRequestPair()
    {
      string line;
      string delimiter=",";
      pair<string,string> edge;
      edge.first="stop";
      edge.second="stop";
      size_t pos =0;
      if(getline(requestfile,line))
      {
        pos=line.find(delimiter);
        edge.first=line.substr(0,pos);
        edge.second=line.substr(pos+2,line.length());
        return edge;
      }
      else
      {
        return edge;
      }
    }

    void setflights()
    {
      string line;
      string delimiter= ",";
      string space= " ";
      size_t pos = 0;

      while(getline(flightfile,line))
      {
        pos = line.find(delimiter);
        flights[num][0]=line.substr(0,pos);
        int pos1=0;
        for(int i=0; i;i++)
        {
          if (isdigit(line[i]))
          {
            pos1=i;
            break;
          }
        }
        flights[num][1]=line.substr(pos+2,pos1-(pos+3));
        line.erase(0,pos1);
        pos=line.find(space);
        string flight_num=line.substr(0,pos);
        flights[num][2]=flight_num;
        string cost = line.substr(pos+1,line.length());
        flights[num][3]=cost;
        num=num+1;
      }
    }

    string getflightNum(string f, string s)
    {
      for(int i=0;i<=num;i++)
      {
        if(flights[i][0]==f && flights[i][1]==s)
        {
          return flights[i][2];
        }
      }
    }

    string getFlightCost(string f, string s)
    {
      for(int i=0;i<=num;i++)
      {
        if(flights[i][0]==f && flights[i][1]==s)
        {
          return flights[i][3];
        }
      }
    }

    pair <string,string> getPair()
    {
      string line;
      string delimiter=",";
      pair<string,string> edge;
      edge.first="stop";
      edge.second="stop";
      size_t pos =0;
      if(getline(requestfile,line))
      {
        pos=line.find(delimiter);
        edge.first=line.substr(0,pos);
        edge.second=line.substr(pos+2,line.length());
        return edge;
      }
      else
      {
        return edge;
      }
    }
  };

class Map
{
  int V;
  list <string> *adj;
  string cities[20][2];


public:

  Map(int V)
  {
    adj = new list <string> [V];
  }

  void SetV()
  {
    int tem=0;
    readin temp("cityFile.txt","flightFile.txt","requestFile.txt");
    string line;
    //while(true)
    for(int i=0; i<20;i++)
    {
      line=temp.getName();
      /*if(line=="fin")
      {
        cout<<"the loop breaks";
        break;
      }*/
      cities[tem][0]=line;
      cities[tem][1]=" ";
      tem++;
    }
    V=tem;
  }

  bool checkCity(string city)
  {
    for(int i=0;i;i++)
    {
      if(cities[i][0]==city)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  void addEdge(string v,string w)
  {
    int pos=0;
    for(int i=0;i;i++)
    {
      if(cities[i][0]==v)
      {
        pos=i;
        break;
      }
    }
      adj[pos].push_back(w);
  }

  void unvisitAll()
  {
    for(int i=0;i<V;i++)
    {
      cities[i][1]=" ";
    }
  }

  void markVisited(string visit)
  {
    for(int i=0;i<V;i++)
      {
        if(cities[i][0]==visit)
        {
          cities[i][1]="v";
        }
      }
  }

  string getNextCity(string topCity)
  {
    int pos=0;
    for(int i=0; i<V;i++)
    {
      if(cities[i][0]==topCity)
      {
        pos=i;
      }
    }
    for(list<string>::iterator it = adj[pos].begin();it != adj[pos].end();it++)
    {
      for(int i=0;i<V;i++)
      {
        if(cities[i][0]==*it&&cities[i][1]==" ")
        {
          return *it;
        }
      }
    }
    return " ";
    }

    bool isPath(string originCity, string destinationCity)
    {
      bool success;
      OurStack <string> aStack;
      unvisitAll();
      aStack.push(originCity);
      markVisited(originCity);
      string topCity=aStack.peek();
      while(!aStack.isEmpty()&&(topCity != destinationCity))
        {
          string nextCity = getNextCity(topCity);
          if(nextCity==" ")
          {
            aStack.pop();
          }
          else
          {
            aStack.push(nextCity);
            markVisited(nextCity);
          }
          if(!aStack.isEmpty())
          {
            topCity=aStack.peek();
          }
        return !aStack.isEmpty();
        }
    }
};







int main()
{
cout<<"hey"<<endl;
pair <string,string> connection,request;
readin rf("cityFile.txt","flightFIle.txt","requestFile.txt");
Map map(3);
map.SetV();
  while(true)
  {
    connection=rf.getNamePair();
    if(connection.first=="stop")
    {
      break;
      map.addEdge(connection.first,connection.second);
    }
  }
  while(true)
  {
    request=rf.getRequestPair();
    if(request.first=="stop")
    {
      break;
    }
    cout<<"Request is to fly from"<<request.first<<request.second<<endl;
    if(!map.checkCity(request.first))
    {
      cout<<"sorry Hpair doesnt serve"<<request.first<<request.second<<endl;
    }
    else if(map.isPath(request.first,request.second))
    {
      cout<<"hpair does fly from"<<request.first<<request.second<<endl;
    }
    else
    {
      cout<<"sorry hpair doesnt fly from"<<request.first<<request.second<<endl;
    }

  }
return 0;
}