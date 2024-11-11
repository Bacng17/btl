#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class sinhvien{
    string ma;
    string ten;
    int tuoi;
    double diem;
public:
    sinhvien(string ma, string ten, int tuoi, double diem): ma(ma), ten(ten), tuoi(tuoi), diem(diem) {}
    sinhvien() = default;
    string getma() const { return ma; }
    string getten() const { return ten; }
    int gettuoi() const { return tuoi; }
    double getdiem() const { return diem; } 
    void setten(string tenmoi) { ten = tenmoi; }
    void settuoi(int tuoi) { this->tuoi = tuoi; }
    void setdiem(double diem) { this->diem = diem; }
    bool operator<(const sinhvien &sv) const { return diem < sv.diem; }
    bool operator>(const sinhvien &sv) const { return diem > sv.diem; }
    friend ostream &operator<<(ostream &os, const sinhvien &sv) {
        os<<"Ma:"<<sv.ma<<" Ten:"<<sv.ten<<" Tuoi:"<<sv.tuoi<<" Diem:"<<sv.diem;
        return os;
    }
    friend istream &operator>>(istream &is, sinhvien &sv) {
        cout<<"Nhap ma:";is>>sv.ma;          
        cout<<"Nhap ten:";is.ignore(); getline(is, sv.ten);  
        cout<<"Nhap tuoi:";is>>sv.tuoi;
        cout<<"Nhap diem:";is>>sv.diem;
        return is;
    }
};
class quanlysinhvien{
    vector<sinhvien> danhsach;
public:
    void themsinhvien(sinhvien sv){ 
        danhsach.push_back(sv);
    }
    void hienthidanhsach() const{
	    if(danhsach.empty()){  
	        cout<<"Danh sach sinh vien trong.\n";
	    } 
		else{
	        for(const auto sv : danhsach){
	            cout<<sv<<endl;
	        }
	    }
	}
    void sapxeptheodiem(){
        sort(danhsach.begin(), danhsach.end(), greater<sinhvien>());
    }
    void timkiemsinhvien(string ten) const{
	    bool c = false;
	    for( auto &sv : danhsach){
	        if(sv.getten() == ten){
	            cout<<"Sinh vien tim thay: "<<sv<< endl;
	            c = true;
	        }
	    }
	    if(!c){
	        cout<<"Khong tim thay sinh vien co ten: "<<ten<< endl;
	    }
	}	
    void xoasinhvien(string ma){
	    for (auto it = danhsach.begin(); it != danhsach.end(); ) {
	        if (it->getma() == ma){
	            it = danhsach.erase(it);
	            cout << "Da xoa sinh vien co ma: " << ma << endl;
	        } 
			else {
	            ++it;
	        }
	   	}
	}
    void suasinhvien(string ma){
    for(auto it = danhsach.begin(); it != danhsach.end(); ++it){
        if(it->getma() == ma){
            string ten;
            int tuoi;
            double diem;
            cout<<"Nhap ten moi:"; 
            cin.ignore(); 
            getline(cin, ten);
            cout<<"Nhap tuoi moi:";cin>>tuoi;
            cout<<"Nhap diem moi:";cin>>diem;
            it->setten(ten);
            it->settuoi(tuoi);
            it->setdiem(diem);
            cout<<"Da sua thong tin sinh vien:"<<*it<<endl;
            return; 
        }
    }
    cout << "Khong tim thay sinh vien co ma: " << ma << endl;
}
};
class menu{
    quanlysinhvien qlsv;
public:
    void hienthimenu(){
        int c;
        do {
            cout<<"\n--- MENU QUAN LY SINH VIEN ---\n";
            cout<<"1. Them sinh vien\n";
            cout<<"2. Hien thi danh sach\n";
            cout<<"3. Sap xep sinh vien theo diem\n";
            cout<<"4. Tim kiem sinh vien theo ten\n";
            cout<<"5. Xoa sinh vien theo ma\n";
            cout<<"6. Sua thong tin sinh vien\n";
            cout<<"7. Thoat\n";
            cout<<"Nhap lua chon:";
            cin>>c;
            xuly(c);
        } 
		while(c != 7);
    }
    void xuly(int c){
        if (c == 1){
            char a;
            do {
                sinhvien sv;
                cin>>sv;
                qlsv.themsinhvien(sv);
                cout<<"Sinh vien da duoc them:"<<sv<<endl;
                cout<<"Ban co muon nhap them sinh vien (c/k)?"; 
                cin>>a;
                while(a != 'c' && a != 'C' && a != 'k' && a != 'K'){
                	cout<<"Lua chon khong hop le, vui long nhap lai(c/k): "; 
                	cin>>a;
            	}
            } 
			while(a == 'c' || a == 'C');
        } 
		else if(c == 2){
            qlsv.hienthidanhsach();
        } 
		else if(c == 3){
            qlsv.sapxeptheodiem();
            cout<<"Da sap xep danh sach theo diem.\n";
        } 
		else if(c == 4){
            string ten;
            cout<<"Nhap ten sinh vien can tim:"; 
            cin.ignore();  
            getline(cin, ten);
            qlsv.timkiemsinhvien(ten);
        } 
		else if(c == 5){
            string ma;
            cout<<"Nhap ma sinh vien can xoa:"; 
            cin>>ma;
            qlsv.xoasinhvien(ma);
        } 
		else if(c == 6){
            string ma;
            cout<<"Nhap ma sinh vien can sua:"; 
            cin>>ma;
            cin.ignore();
            qlsv.suasinhvien(ma);
        } 
		else if(c == 7){
            cout<<"Thoat chuong trinh.\n";
        } 
		else {
            cout<<"Lua chon khong hop le.\n";
        }
    }
};

int main(){
    menu mn;
    mn.hienthimenu();
    return 0;
}

