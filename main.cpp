#include <iostream>
#include <cstdlib>
using namespace std;

class DjackaKnjizica
{
private:
    int godina;
    double prosek;
public:
    DjackaKnjizica(){godina = 2; prosek = 5.00;}
    DjackaKnjizica(int g,double p){godina = g; prosek = p;}
    DjackaKnjizica(const DjackaKnjizica &k) {godina = k.godina; prosek = k.prosek;}

    int getGodina()const{return godina;}
    double getProsek()const{return prosek;}

    void setGodina(int gg)
    {
        if(gg>=1 && gg<=4)
            godina = gg;
        else
            cout<<"Nepostojeca godina"<<endl;
    }
    void setProsek(double pro)
    {
        if(pro>=1 && pro<=5)
            prosek = pro;
        else
            cout<<"Nevazeci prosek"<<endl;
    }
};

enum VrstaSkole {STRUCNA,GIMNAZIJA,UMETNICKA};
enum StepenSkole {TROGODISNJA,CETVOROGODISNJA};

class Skola
{
private:
    VrstaSkole vrsta;
    StepenSkole stepen;
public:
    Skola(){vrsta = GIMNAZIJA; stepen = CETVOROGODISNJA;}
    Skola(VrstaSkole v,StepenSkole s){vrsta = v; stepen = s;}
    Skola(const Skola &ss){vrsta = ss.vrsta; stepen = ss.stepen;}

    VrstaSkole getVrstaS()const{return vrsta;}
    StepenSkole getStepenS()const{return stepen;}

    void setVrstaS(VrstaSkole sk){vrsta = sk;}
    void setStepenS(StepenSkole st){stepen = st;}

};

enum Pozicija {kuca,biblioteka,ucionica,trening};

class Ucenik
{
private:
    DjackaKnjizica djackaKnjizica;
    Skola skola;
    int vestina;
    int znanje;
    int odmor;
    Pozicija pozicija;
public:
    Ucenik():djackaKnjizica(),skola(){vestina = 50; znanje = 50; odmor = 50; pozicija = kuca;}
    Ucenik(int god,double prosk,VrstaSkole vs,StepenSkole ss,int v,int z,int o,Pozicija p):djackaKnjizica(god,prosk),skola(vs,ss)
    {
        if((v>=1 && v <=100)&&(z>=1 && z <=100)&&(o>=1 && o <=100))
        {
            vestina = v;
            znanje = z;
            odmor = o;
        }
            pozicija = p;
    }
    Ucenik(const Ucenik &u):djackaKnjizica(u.djackaKnjizica),skola(u.skola)
    {
        if((u.vestina>=1 && u.vestina <=100)&&(u.znanje>=1 && u.znanje <=100)&&(u.odmor>=1 && u.odmor <=100))
        {
            vestina = u.vestina;
            znanje = u.znanje;
            odmor = u.odmor;
        }
            pozicija = u.pozicija;
    }
    bool idiKuci()
    {
        if(pozicija != kuca)
        {
            pozicija = kuca;
            return true;
        }else
            return false;
    }
    bool idiNaTrening()
    {
        if(pozicija == kuca && odmor > 60)
        {
            pozicija = trening;
            return true;
        }else
            return false;
    }
    bool idiUBiblioteku()
    {
        if(pozicija == kuca || pozicija == ucionica)
        {
            pozicija = biblioteka;
            return true;
        }else
            return false;
    }
    bool idiUUcionicu()
    {
        if(pozicija == biblioteka)
        {
            pozicija = ucionica;
            return true;
        }else
            return false;
    }
    bool spavaj(int satiSna)
    {
        if(pozicija == kuca)
        {
            odmor = satiSna*10;
            if(odmor<=100)
                return true;
        }else
            return false;
    }
    bool uci()
    {
        if(pozicija == biblioteka)
        {
            znanje += rand()%9 + 1;
            if(znanje<=100)
                return true;
        }else
            return false;
    }
    bool treniraj()
    {
        if(pozicija == trening)
        {
            vestina += rand()%9 + 1;
            if(vestina<=100)
                return true;
        }else
            return false;
    }
    bool poloziGodinu()
    {
        if(pozicija == ucionica && znanje>60)
        {
            if(znanje>=60 && znanje<=70)
            {
                djackaKnjizica.setGodina(djackaKnjizica.getGodina()+1);
                djackaKnjizica.setProsek((djackaKnjizica.getProsek() + 2)/2);
            }else if(znanje>70 && znanje<=80)
            {
                djackaKnjizica.setGodina(djackaKnjizica.getGodina()+1);
                djackaKnjizica.setProsek((djackaKnjizica.getProsek() + 3)/2);
            }else if(znanje>80 && znanje<=90)
            {
                djackaKnjizica.setGodina(djackaKnjizica.getGodina()+1);
                djackaKnjizica.setProsek((djackaKnjizica.getProsek() + 4)/2);
            }else if(znanje>80 && znanje<=90)
            {
                djackaKnjizica.setGodina(djackaKnjizica.getGodina()+1);
                djackaKnjizica.setProsek((djackaKnjizica.getProsek() + 5)/2);
            }
            return true;
        }else
            return false;
    }
    bool maturiraj()
    {
        int i;
        i = rand()%4 + 1;
        if(pozicija == ucionica)
        {
            if(djackaKnjizica.getGodina()== 3)
            {
                if(skola.getStepenS()== TROGODISNJA)
                {
                    if(i>1)
                    {
                        return true;
                    }else
                        return false;
                }
            }else
                if(skola.getStepenS()== CETVOROGODISNJA)
                {
                    if(i>1)
                    {
                        return true;
                    }else
                        return false;
                }
        }else
            return false;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
