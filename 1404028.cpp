//Code::Blocks
#include<iostream>
#include<cmath>
#define pi 2*(acos(0))
using namespace std;
ostream &shape_names(ostream &str)
{
    str<<"1.Cube 2.Rectangle 3.Circle 4.Sphere 5.Triangle 6.Cone 7.Exit\n";
    return str;
}
class shape{
    public:
    virtual double area()=0;
    virtual double volume()=0;
    friend istream& operator>>(istream& in,shape *sh);
};
class cube:virtual public shape{
    double ar,w,d,h,vol;
    public:
    friend istream& operator>>(istream &in,cube &cu);

double area()
{
    ar=(w*d+w*h+h*d)*2; return ar;
}
double volume()
{
    vol=h*w*d;
    return vol;
}

};
istream& operator>>(istream &in,cube &cu)
{
    cout<<"---Cube---\n\n"<<"Height : ";
    in>>cu.h;
    cout<<"Width : ";
    in>>cu.w;
    cout<<"Depth : ";
    in>>cu.d;
    cout<<endl;
    return in;
}
class rect:virtual public shape{
    double a,b,ar;
    public:
    friend istream& operator>>(istream &in,rect &rec);
double area()
{
    ar=a*b;
    return ar;
}
double volume() { return 0;}
};
istream& operator>>(istream &in,rect &rec)
{
    cout<<"---Rectangle---\n\n"<<"Height : ";
    in>>rec.a;
    cout<<"Width : ";
    in>>rec.b;
    cout<<endl;
    return in;
}
class circle:virtual public shape{
    double ar,r;
    public:
     friend istream& operator>>(istream &in,circle &cir);

double area()
{
    ar=pi*r*r; return ar;
}
double volume() {return 0;}
};
istream& operator>>(istream &in,circle &cir)
{
    cout<<"---Circle----\n\n"<<"Radius : ";
    in>>cir.r; cout<<endl;
    return in;
}

class sphere:virtual public shape{
    double ar,r,vol;
    public:
friend istream& operator>>(istream &in,sphere &sp);
double area()
{
    ar=4*pi*r*r; return ar;
}
double volume()
{
   vol=(4.0/3.0)*pi*r*r*r;
   return vol;
}
};
istream& operator>>(istream &in,sphere &sp)
{
    cout<<"---Sphere----\n\n"<<"Radius : ";
    in>>sp.r; cout<<endl;
    return in;
}

class triangle:virtual public shape{
    double ar,b,h,vol;
    public:
    friend istream& operator>>(istream &in,triangle &tri);

double area()
{
    ar=.5*b*h; return ar;
}
double volume()
{
    vol=0;
    return vol;
}};
istream& operator>>(istream &in,triangle &tri)
{
    cout<<"---Triangle---\n\n"<<"Height : ";
    in>>tri.h;
    cout<<"Base : ";
    in>>tri.b;
    cout<<endl;
    return in;
}
class cone:virtual public shape{
    double ar,r,l,h,vol;
    public:
    static double cu_ar;
    friend istream& operator>>(istream &in,cone &con);

double area()
{
    ar=pi*r*l+pi*r*r; return ar;
}
double volume()
{
    vol=pi*r*r*h*(1.0/3.0);
    return vol;
}};
istream& operator>>(istream &in,cone &con)
{
    cout<<"---Cone---\n\n"<<"Height : ";
    in>>con.h;
    cout<<"Length Of Slant : ";
    in>>con.l;
    cout<<"Radius Of Base : ";
    in>>con.r;
    cout<<endl;
    return in;
}

class work:public cube,public rect,public circle,public sphere,public triangle,public cone
{
public:
    int sw,t,j,chng;
    static int rct,cr,no,no_del,cb,sp,cn,tr,i;
    shape *sh[10]; cube cu[10]; rect rec[10];  circle cir[10]; triangle tri[10]; cone con[10];
    sphere sphr[10];
    static double all_volume[100],all_area[100],are,vol;
    static void wrk();

void work_cal()
{   while(1)
        {
        cout<<"New Shape<< ENTER CHOICE >>\n\n"<<shape_names;
        cin>>sw;
        switch(sw)
        {
        case 1:
            i++; cb++;
            cout<<"\n==== Shape Number "<<i<<" ===="<<endl<<endl;
            cin>>cu[i];
            sh[i]=&cu[i];
            all_area[i]=sh[i]->area();
            all_volume[i]=sh[i]->volume();
        break;
        case 2:
            i++; rct++;
            cout<<"\n==== Shape Number "<<i<<" ===="<<endl<<endl;
            cin>>rec[i];
            sh[i]=&rec[i];
            all_area[i]=sh[i]->area();
            all_volume[i]=sh[i]->volume();
        break;
        case 3:
            i++; cr++;
            cout<<"\n==== Shape Number "<<i<<" ===="<<endl<<endl;
            cin>>cir[i];
            sh[i]=&cir[i];
            all_area[i]=sh[i]->area();
            all_volume[i]=sh[i]->volume();
        break;
        case 4:
            i++; sp++;
            cout<<"\n==== Shape Number "<<i<<" ===="<<endl<<endl;
            cin>>sphr[i];
            sh[i]=&sphr[i];
            all_area[i]=sh[i]->area();
            all_volume[i]=sh[i]->volume();
        break;
        case 5:
            i++; tr++;
            cout<<"\n==== Shape Number "<<i<<" ===="<<endl<<endl;
            cin>>tri[i];
            sh[i]=&tri[i];
            all_area[i]=sh[i]->area();
            all_volume[i]=sh[i]->volume();
        break;
        case 6:
            i++; cn++;
            cout<<"\n==== Shape Number "<<i<<" ===="<<endl<<endl;
            cin>>con[i];
            sh[i]=&con[i];
            all_area[i]=sh[i]->area();
            all_volume[i]=sh[i]->volume();
        break;
        }
        if(sw==7) break;
        if(sw>7)
            cout<<"\nInvalid Choice . \n";
}}
void del()
{
    cout<<"Which Shape?\n";
    cin>>no_del;
    if(no_del>i) cout<<"\nError! No Shape At "<<no_del;
    else{cout<<"Deleting Shape No "<<no_del<<" !";
    all_area[no_del]=0;
    all_volume[no_del]=0;
    }

}
double area()
{
    are=0;
   for(j=1;j<=i;j++)
    {
        are=are+all_area[j];
    }
 return are;

}
double volume()
{
    vol=0;
    for(int k=1;k<=i;k++)
        vol=vol+all_volume[k];
    return vol;
}

void change()
{
    are=0;
    cout<<"Enter Shape Number << Change To A New Shape >>\n";
    cin>>no;
    all_area[no]=0;
    all_volume[no]=0;
    if(no>i) cout<<"\nError! No Shape At "<<no;
    else if(no==no_del) cout<<"\nShape Number "<<no<<" Is Deleted\n";
    else
    {
    cout<<"\nChange To Which Shape? \n"<<shape_names;
string a[6]={"Shape Cube","Shape Recntangle","Shape Circle","Shape Sphere","Shape Triangle","Shape Cone"};
    cin>>chng;
    switch(chng)
    {
    case 1:cb++;
        cin>>cu[cb];
        sh[no]=&cu[cb];
        all_area[no]=sh[no]->area();
        all_volume[no]=sh[no]->volume();
        cout<<"\n==Shape Number "<<no<<" Is Changed To "<<a[chng-1]<<"=="<<endl;
    break;
    case 2:
        rct++;
        cin>>rec[rct];
        sh[no]=&rec[rct];
        all_area[no]=sh[no]->area();
        all_volume[no]=sh[no]->volume();
        cout<<"\n==Shape Number "<<no<<" Is Changed To "<<a[chng-1]<<"=="<<endl;
    break;
      case 3:cr++;
        cin>>cir[cr];
        sh[no]=&cir[cr];
        all_area[no]=sh[no]->area();
        all_volume[no]=sh[no]->volume();
        cout<<"\n==Shape Number "<<no<<" Is Changed To "<<a[chng-1]<<"=="<<endl;
    break;
    case 4:sp++;
        cin>>sphr[sp];
        sh[no]=&sphr[sp];
        all_area[no]=sh[no]->area();
        all_volume[no]=sh[no]->volume();
        cout<<"\nShape Number "<<no<<" Is Changed To "<<a[chng-1]<<endl;
    break;
     case 5: tr++;
        cin>>tri[tr];
        sh[no]=&tri[tr];
        all_area[no]=sh[no]->area();
        all_volume[no]=sh[no]->volume();
        cout<<"\nShape Number "<<no<<" Is Changed To "<<a[chng-1]<<endl;
    break;
     case 6: cn++;
        cin>>con[cn];
        sh[no]=&con[cn];
        all_area[no]=sh[no]->area();
        all_volume[no]=sh[no]->volume();
        cout<<"\nShape Number "<<no<<" Is Changed To "<<a[chng-1]<<endl;
    break;
    }}}


friend void edit(work wr);
};

istream& operator>>(istream &in,shape *sh)
{
    cube cu; rect rec; circle cir; sphere sp; triangle tri; cone con; work wr;
    if(dynamic_cast<cube*>(sh))
    {
        in>>cu;
        wr.all_area[work::no]=cu.area();
        wr.all_volume[work::no]=cu.volume();
    }
    else if(dynamic_cast<rect*>(sh))
    {
        in>>rec;
        wr.all_area[work::no]=rec.area();
        wr.all_volume[work::no]=rec.volume();
    }
    else if(dynamic_cast<circle*>(sh))
    {
        in>>cir;
        wr.all_area[work::no]=cir.area();
        wr.all_volume[work::no]=cir.volume();
    }
    else if(dynamic_cast<sphere*>(sh))
    {
        in>>sp;
        wr.all_area[work::no]=sp.area();
        wr.all_volume[work::no]=sp.volume();
    }
    else if(dynamic_cast<triangle*>(sh))
    {
        in>>tri;
        wr.all_area[work::no]=sp.area();
        wr.all_volume[work::no]=sp.volume();
    }
    else if(dynamic_cast<cone*>(sh))
    {
        in>>con;
        wr.all_area[work::no]=sp.area();
        wr.all_volume[work::no]=sp.volume();
    }
    return in;
}

void edit(work wr)
{
    wr.are=0;
    cout<<"Edit: Shape Number?\n";
    cin>>wr.no;
    if(wr.no>wr.i)
        cout<<"\nError! There's No Shape At "<<wr.no;
    else if(wr.no==work::no_del) cout<<"\nShape Number "<<wr.no<<" Is Deleted\n";
    else
       cin>>wr.sh[wr.no];

}
int work::no_del=0;
int work::cb=0;
int work::i=0;
int work::cr=0;
int work::rct=0;
int work::sp=0;
int work::tr=0;
int work::cn=0;
int work::no=0;
double work::are=0;
double work::vol=0;
double work::all_area[100]={0};
double work::all_volume[100]={0};

void work::wrk()
{cout<<"Number Of Shapes Initially : "<<work::i<<endl<<endl;}
main()
{
    int x,c=0;
    work wr;
    work::wrk();
    wr.work_cal();
    cout<<"\nTotal Area=="<<wr.area()<<endl;
    cout<<"\nTotal Volume=="<<wr.volume()<<endl;
    while(1)
    {
    cout<<"\n<<Enter Choice>>";
    cout<<"\n\n1.Edit Dimension\n2.Change Particular Shape\n3.Add More Shape\n";
    cout<<"4.Show New Total Area & Volume\n5.Delete\n6.Exit Program\n";
    cin>>x;
    switch(x)
    {
    case 1:
    edit(wr); break;
    case 2:
    wr.change(); break;
    case 3:
    wr.work_cal();
    break;
    case 4:
    cout<<"\nNew Total Area=="<<wr.area()<<endl;
    cout<<"\nNew Total Volume=="<<wr.volume()<<endl;
      break;
    case 5:
    wr.del();
    break;  }
    if(x>=6) { cout<<"You Have Entered : "<<wr.i<<" Shape<s>"<<endl<<endl; break;}}
    return 0;
}

