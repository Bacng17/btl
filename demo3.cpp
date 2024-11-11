#include<iostream>
#include<string>
#include<cctype> 
using namespace std;
class KhachHang{
    int maKH;
    string hoten;
    string sdt;
    KhachHang *next;
    KhachHang *pre;
public:
    KhachHang(int ma, string ht, string so){
        maKH = ma;
        hoten = ht;
        sdt = so;
        next = nullptr;
        pre = nullptr;
    }
    int getmaKH() const { return maKH; }
    void setmaKH(int ma) { maKH = ma; }
    string gethoten() const { return hoten; }
    void sethoten(string ht){ hoten = ht; }
    string getsdt() const { return sdt; }
    void setsdt(string so){ sdt = so; }
    KhachHang *getnext(){ return next; }
    void setnext(KhachHang *nextkh){ next = nextkh; }
    KhachHang *getpre(){ return pre; }
    void setpre(KhachHang *prekh){ pre = prekh; }
};
class DanhSachKH{
    KhachHang *head, *tail;
public:
    DanhSachKH(){
        head = tail = nullptr;
    }
    int nhapma(string thongbao){
        int so;   
        while(true){
        	cout<<thongbao;
        	cin>>so;
            if(cin.fail()){
                cout<<"Nhap ko dung dinh dang, vui long nhap lai\n";
                cin.clear();
                cin.ignore(1000, '\n');
            } 
            else{
            	cin.ignore(1000, '\n');
                return so;
            }
        }
    }
    string nhapsdt(string thongbao){
        string so;
        while(true){
        	cout<<thongbao;
        	cin>>so;
            if(so.length() != 10 || !sdt(so)){
                cout<<"Nhap so dien thoai sai dinh dang, vui long nhap lai: ";
            }
            else{
                return so;
            }
        }
    }
    bool sdt(const string phone){
        if(phone.length() != 10){
            return false;
        }
        for(char c : phone){
            if(!isdigit(c)){  
                return false;
            }
        }
        return true;
    }
    bool ktrama(int makh){
        KhachHang *c = head;
        while(c != nullptr){
            if(c->getmaKH() == makh){
                return true;
            }
            c = c->getnext();
        }
        return false;
    }
    bool ktrasdt(string sdt){
        KhachHang *c = head;
        while(c != nullptr){
            if(c->getsdt() == sdt){
                return true;
            }
            c = c->getnext();
        }
        return false;
    }
    void themKH(){
        int maKH;
        string ht, sdt;
        char c;
        do{
        	maKH = nhapma("Nhap ma khach hang: ");
            if (ktrama(maKH)) {
               	cout<< "Ma khach hang nay da co, vui long nhap lai\n";
               	continue; 
           	} 
            cout<<"Nhap ho ten khach hang: ";
            getline(cin, ht); 
			do{ 
				sdt = nhapsdt("Nhap so dien thoai:");
				if(ktrasdt(sdt)){
					cout<<"So dien thoai nay da co, vui long nhap lai\n";
				}
			} 
			while(ktrasdt(sdt)); 
            KhachHang *khachhang = new KhachHang(maKH, ht, sdt);
            if(tail == nullptr){
                head = tail = khachhang;
            }
            else{
                tail->setnext(khachhang);
                khachhang->setpre(tail);
                tail = khachhang;
            }
            cout<<"Ban co muon nhap tiep ko(Y/N)? :";
            cin>>c;
            if(c == 'N' || c == 'n'){
                break;
            }
            while(c != 'Y' && c != 'y' && c != 'N' && c != 'n'){
                cout<<"Ban nhap ko dung dinh dang, vui long nhap lai(Y/N) :";
                cin>>c;
            }
        }
        while(c == 'Y' || c == 'y');
    }
    KhachHang *timkiem(int makh){
        KhachHang *c = head;
        while(c != nullptr){
            if(c->getmaKH() == makh){
                return c;
            }
            c = c->getnext();
        }
        return nullptr;
    }
    // Xoa kh
    void xoa(int makh){
        KhachHang *customer = timkiem(makh);
        if(customer == nullptr){
            cout << "Khach hang khong ton tai\n";
            return;
        }
        if(customer->getpre() == nullptr){
            head = head->getnext();
        }
        else{
            customer->getpre()->setnext(customer->getnext());
        }
        if(customer->getnext() == nullptr){
            tail = tail->getpre();
        }
        else{
            customer->getnext()->setpre(customer->getpre());
        }
        delete customer;
        cout<<"Da xoa khach hang.\n";
    }
    // Sua
    void suatt(int makh) {
        KhachHang *customer = timkiem(makh);
        if (customer == nullptr) {
            cout << "Khach hang khong ton tai.\n";
            return;
        }
        string ht, sdt;
        cout<<"Nhap ho ten moi: ";
        cin.ignore(1); 
        getline(cin, ht);
        customer->sethoten(ht);
        sdt = nhapsdt("Nhap so dien thoai khach hang: ");
        customer->setsdt(sdt);
        cout << "Da sua thong tin\n";
    }
    // In
    void in(){
        KhachHang *c = head;
        if (c == nullptr){
            cout<<"Danh sach khach hang trong\n";
        }
        else{
            cout<<"Danh sach khach hang:\n";
            while(c != nullptr){
                cout<<"Ma KH: "<<c->getmaKH()<<" Ho ten: "<<c->gethoten()<<" Sdt: "<< c->getsdt()<< "\n";
                c = c->getnext();
            }
        }
    }
    void search(){
        int makh = nhapma("Nhap ma khach hang can tim: ");
        KhachHang *customer = timkiem(makh);
        if(customer == nullptr){
            cout<<"Ma KH ko ton tai\n";
            return;
        }
        cout<<"Khach hang tim thay: Ma KH: "<<customer->getmaKH()<<" Ho ten: "<<customer->gethoten()<<" SDT: "<<customer->getsdt()<<"\n";
        int c;
        do{
            cout<<"\n---Menu---\n";
            cout<<"1. Xoa khach hang\n";
            cout<<"2. Sua thong tin khach hang\n";
            cout<<"3. Quay lai menu chinh\n";
            cout<<"Nhap: ";
            cin>>c;
            if(c == 1){
                xoa(makh);
            }
            else if(c == 2){
                suatt(makh);
            }
            else if(c == 3){
                break;
            }
            else{
                cout<<"Nhap khong dung dinh dang, vui long nhap lai\n";
            }
        }
        while(c != 3 && c != 1 && c != 2);
    }
};
int main(){
    DanhSachKH ds;
    int c;
    do {
        cout<<"\n---Menu chinh---\n";
        cout<<"1. Nhap khach hang:\n";
        cout<<"2. Tim kiem khach hang:\n";
        cout<<"3. In danh sach KH:\n";
        cout<<"4. Thoat\n";
        cout<<"Nhap: ";
        cin>>c;
        if(c == 1){
            ds.themKH();
        }
        else if(c == 2){
            ds.search();
        }
        else if(c == 3){
            ds.in();
        }
        else if (c == 4){
            cout<<"Thoat";
            break;
        }
        else{
            cout<<"Nhap khong dung dinh dang, vui long nhap lai\n";
        }
    } 
	while(c != 4);
    return 0;
}