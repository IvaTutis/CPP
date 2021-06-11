//#.grupa
#include<iostream>
#include<list>

using namespace std;

class Window{
protected:
  int x,y;
  int visina;
  int sirina;
  int otvoren;
  static list<Window*> L;

public:
  Window(int x,int y,int v,int s) : x(x),y(y),visina(v),sirina(s)
  { otvoren=0;
    L.push_back(this);
  }
  virtual void move(int x1,int y1)=0;
  virtual void close(){otvoren=0;}
  virtual void open(){otvoren=1;}

  bool intersect(Window& r){
   if(!otvoren || !r.otvoren) return false;
   if(r.x>=x && r.x<=(x+sirina))
   {
     if(r.y<=y && r.y>=(y-visina))
       return true;
     else if((r.y-r.visina)<=y) return true;
   }
   else if(r.x<x)
   { if(r.x+sirina>=x && r.y-visina<=y)return true;
   }
   return false;
  }
  void allIntersecting()
  { list<Window*> ::iterator it;
   for(it=L.begin();it!=L.end();++it)
   { if(this!=(*it))
      { if(intersect(*(*it))) cout<<"("<<(*it)->x<<","<<(*it)->y<<","<<(*it)->visina<<","<<(*it)->sirina<<")"<<endl;
      }
   }

  }
  static void ekran(){
  list<Window*> ::iterator it;
  for(it=L.begin();it!=L.end();++it)
  { if((*it)->otvoren) cout<<"("<<(*it)->x<<","<<(*it)->y<<","<<(*it)->visina<<","<<(*it)->sirina<<")"<<endl;
  }

}};
 list<Window*> Window::L;

class ResizableWin : public Window{
public:
  ResizableWin(int x,int y,int v,int s) : Window(x,y,v,s){}
  void changeSize(int v,int s){visina=v,sirina=s;}
  void move(int x1,int y1){ if(otvoren) {x=x1;y=y1;} }
};

class TransparentWin : public Window{
private:
  int prozirnost;

public:
  TransparentWin(int x,int y,int v,int s,int proz) : Window(x,y,v,s)
  { prozirnost=proz;
  }
  void changeTransparencity(int proz)
  { prozirnost=proz;
  }
  void open(){if(prozirnost==100)otvoren =0;
              otvoren=1;}
  void move(int x1,int y1){ if(otvoren) {x=x1;y=y1;} }
};

int main()
{Window* polje[5];
polje[0]=new ResizableWin(0,0,5,5);
polje[1]=new TransparentWin(1,1,3,6,20);
polje[2]=new ResizableWin(6,6,2,2);
polje[3]=new ResizableWin(0,5,2,3);
polje[4]=new TransparentWin(4,4,2,2,100);

polje[0]->open();
polje[1]->open();
polje[2]->open();
polje[3]->open();
polje[4]->open();

Window::ekran();

cout<<(*polje[1]).intersect(*polje[2])<<endl;
(*polje[0]).allIntersecting();
return 0;
}




