#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <climits>

using namespace std;

// ================== LAY DUONG DAN core.exe ==================
string getExeDir() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    string path(buffer);
    return path.substr(0, path.find_last_of("\\/"));
}

// ================== CAU TRUC DU LIEU ==================
class data_sinhvien {
public:
    string masv;
    string ngaysinh;
    string thangsinh;
    string namsinh;
    string name;
    string gioitinh;
    string lop;
    string ngaythangnamsinh;
    string dantoc;
    string noisinh;
    string coso;
};

data_sinhvien sv;

// ================== IN DATA ==================
void in_data(const vector<data_sinhvien>& SV, int i) {
    cout << left
         << setw(13) << SV[i].masv
         << setw(28) << SV[i].name
         << setw(10) << SV[i].gioitinh
         << setw(15) << SV[i].lop
         << setw(15) << SV[i].ngaythangnamsinh
         << setw(15) << SV[i].dantoc
         << setw(15) << SV[i].noisinh
         << setw(15) << SV[i].coso
         << endl;
}

// ================== DOC FILE ==================
void lay_data(vector<data_sinhvien>& SV) {
    string path = getExeDir() + "\\data_sv_uneti_k19.txt";
    ifstream file(path);

    if (!file.is_open()) {
        cout << "Truy Cập Database Không Thành Công!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, sv.masv, '|');
        getline(ss, sv.ngaysinh, '|');
        getline(ss, sv.thangsinh, '|');
        getline(ss, sv.namsinh, '|');
        getline(ss, sv.name, '|');
        getline(ss, sv.gioitinh, '|');
        getline(ss, sv.lop, '|');
        getline(ss, sv.ngaythangnamsinh, '|');
        getline(ss, sv.dantoc, '|');
        getline(ss, sv.noisinh, '|');
        getline(ss, sv.coso);

        SV.push_back(sv);
    }
}

//_________________________________________________________FUNC CHECK DATA________________________________________________________________
// CHECK THEO HO TEN
void check_hoten(const vector<data_sinhvien> &SV,string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].name == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;
}

// CHECK THEO CHI MINH TEN
void check_name(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    for(int i = 0; i < sl_sv; i++)
        if(SV[i].name.find(s) != string::npos)
            in_data(SV,i);
}



// CHECK THEO NAM SINH
void check_namsinh(const vector<data_sinhvien> &SV,string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].namsinh == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;
}

// CHECK THEO NGAY THANG NAM SINH
void check_ngaythangnamsinh(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].ngaythangnamsinh == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;
}

// CHECK THEO NOI SINH
void check_noisinh(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].noisinh == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;
}

// CHECK THEO DAN TOC
void check_dantoc(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].dantoc == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;
    
}

// CHECK THEO LOP
void check_lop(const vector<data_sinhvien> &SV,string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].lop == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;

}


// CHECK THEO MA SINH VIEN
void check_masinhvien(const vector<data_sinhvien> &SV,string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].masv.find(s) != string::npos){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;

}

// CHECK THEO NGAY SINH
void check_ngaysinh(const vector<data_sinhvien> &SV,string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].ngaysinh == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;

}


// CHECK THEO THANG SINH
void check_thangsinh(const vector<data_sinhvien> &SV,string s){
    int sl_sv = SV.size();
    bool kt = false;
    for(int i = 0; i < sl_sv; i ++)
        if(SV[i].thangsinh == s){
            in_data(SV,i);
            kt = true;
        }
    if(!kt) cout << "Không Tìm Thấy Sinh Viên Có Data Trên!"<< endl;

}

//________________________________________________________FUNC TI LE________________________________________________________
// TI LE NAM SINH 
double tile_namsinh(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    double c = 0;
    for (int i = 0; i < sl_sv; i++)
        if (SV[i].namsinh == s)
            c++;
    return (c/sl_sv)*100;
}

// TI LE NOI SINH 
double tile_noisinh(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    double c = 0;
    for (int i = 0; i < sl_sv; i++)
        if (SV[i].noisinh == s)
            c++;
    return (c/sl_sv)*100;
}

// TI LE DAN TOC
double tile_dantoc(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    double c = 0;
    for (int i = 0; i < sl_sv; i++)
        if (SV[i].dantoc == s)
            c++;
    return (c/sl_sv)*100;
}

// TI LE GIOI TINH
double tile_gioitinh(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    double c = 0;
    for (int i = 0; i < sl_sv; i++)
        if (SV[i].gioitinh == s){
            c++;
        }
    return (c/sl_sv)*100;
}



//________________________________________________________FUNC ANALYSIS________________________________________________________
void noisinh_analysis(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    cout << left << setw(20) << "  Nơi Sinh" << setw(20) << "   SL Sinh Viên"  << "    Tỉ Lệ" << endl;
    cout << "________________________________________________________________________________________________________________________" <<endl;
    for(int i = 0; i < sl_sv; i++){
        bool kt = true;
        for(int j = 0; j < i; j++){
            if(SV[j].noisinh == SV[i].noisinh){
                kt = false;
                break;
            }
        }
        int sl = 0;
        for(int k = 0; k < sl_sv; k ++)
            if(SV[i].noisinh == SV[k].noisinh)
                sl++;
        if(kt)
            cout << left << "  "<< setw(20) << SV[i].noisinh << setw(20) << sl << fixed << setprecision(2) << tile_noisinh(SV, SV[i].noisinh) <<"%" << endl;
    }
}

void dantoc_analysis(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    cout << left << setw(22) << "  Dân Tộc" << setw(20) << "   SL Sinh Viên"  << "    Tỉ Lệ" << endl;
    cout << "________________________________________________________________________________________________________________________" <<endl;
    for(int i = 0; i < sl_sv; i++){
        bool kt = true;
        for(int j = 0; j < i; j++){
            if(SV[j].dantoc == SV[i].dantoc){
                kt = false;
                break;
            }
        }
        int sl = 0;
        for(int k = 0; k < sl_sv; k ++)
            if(SV[i].dantoc == SV[k].dantoc)
                sl++;
        if(kt)
            cout << left << "  "<< setw(20) << SV[i].dantoc << setw(20) << sl << fixed << setprecision(2) << tile_dantoc(SV, SV[i].dantoc) <<"%" << endl;
    }
}


void namsinh_analysis(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    cout << left << setw(20) << "  Năm Sinh" << setw(20) << "   SL Sinh Viên"  << "    Tỉ Lệ" << endl;
    cout << "________________________________________________________________________________________________________________________" <<endl;
    for(int i = 0; i < sl_sv; i++){
        bool kt = true;
        for(int j = 0; j < i; j++){
            if(SV[j].namsinh == SV[i].namsinh){
                kt = false;
                break;
            }
        }
        int sl = 0;
        for(int k = 0; k < sl_sv; k ++)
            if(SV[i].namsinh == SV[k].namsinh)
                sl++;
        if(kt)
            cout << left << "  "<< setw(20) << SV[i].namsinh << setw(20) << sl << fixed << setprecision(2) << tile_namsinh(SV, SV[i].namsinh) <<"%" << endl;
    }
}


void soluongsv_analysis(const vector<data_sinhvien> &SV, string s){
    int sl_sv = SV.size();
    int sl1 ; // sl so sanh max
    int sl2 ; // sl so sanh min
    int max = 0, min = INT_MAX, pos_max, pos_min; // sl sv max, sl sv min, vitri max, vitri min
    cout << left << setw(20) << "  Lớp" << setw(20) << "SL Sinh Viên" << endl;
    cout << "________________________________________________________________________________________________________________________" <<endl;
    for(int i = 0; i < sl_sv; i ++){
        bool kt = true;
        for(int j = 0; j < i; j++)
            if(SV[j].lop == SV[i].lop){
                kt = false;
                break;
            }
        int sl = 0; // sl sinh vien trong 1 lop
        for(int k = 0; k < sl_sv; k++)
            if(SV[k].lop == SV[i].lop)
                sl++;
        sl1 = sl;
        sl2 = sl;
        if(sl1 > max){
            max = sl1;
            pos_max = i;
        }
        if(sl2 < min){
            min = sl2;
            pos_min = i;
        }
        if(kt){
            cout << left << "  "<< setw(20) << SV[i].lop << sl << endl;
        }
    }
    cout <<  SV[pos_max].lop << " Là Lớp Có Nhiều Sinh Viên Nhất Với " << max << " Sinh Viên" << endl;
    cout << SV[pos_min].lop << " Là Lớp Có Nhiều Sinh Viên Nhất Với " << min << " Sinh Viên" << endl;
    cout << endl;
}







// ================== MAIN ==================
int main(int argc, char* argv[]) {
    if (argc < 3) return 0;
    int option = stoi(argv[1]);
    string check = argv[2];
    string key;
    if (option < 15) {
        key = argv[2];
        if (check == "") {
            key = "nonexyz";
            cout << "Vui Lòng Nhập Dữ Liệu!";
            return 0;
        }
    }
    else if (option >= 15) key = "none";

    

    vector<data_sinhvien> SV;
    lay_data(SV);

    //______________________________________________CALL FUCNTION________________________________________________//  
    //check_namsinh(SV,2007);
    //check_noisinh(SV,"Thanh Hoa");
    //check_dantoc(SV, "Kinh");
    //check_ngaythangnamsinh(SV,"16/06/2007");
    //check_name(SV,"Duy");
    //check_hoten(SV,"Trinh Xuan Duy");
    //check_lop()
    //check_ngaysinh()
    //check_thangsinh()
    //check_lop()
    //check_masinhvien()

    //tile_namsinh(SV,2007);
    //tile_noisinh(SV, "Thanh Hoa");
    //tile_dantoc(SV, "Kinh");
    //tile_gioitinh(SV, "Nam");
    //___________________________________________________________________________________________________________//

    switch (option) {
        // Search
        case 1: check_hoten(SV, key); break;
        case 2: check_masinhvien(SV, key); break;
        case 3: check_lop(SV, key); break;
        case 4: check_name(SV, key); break;
        case 5: check_ngaythangnamsinh(SV, key); break;
        case 6: check_noisinh(SV, key); break;
        case 7: check_dantoc(SV, key); break;
        case 8: check_ngaysinh(SV, key); break;
        case 9: check_thangsinh(SV, key); break;
        case 10: check_namsinh(SV, key); break;
        // Check Ti Le
        case 11: cout << "Ti lệ sinh viên sinh năm " << argv[2] << " là : "<<tile_namsinh(SV,key) << "%";break;
        case 12: cout << "Tỉ lệ sinh viên ở " << argv[2] << " là : "<< tile_noisinh(SV,key) <<"%"; break;
        case 13: cout << "Tỉ lệ sinh viên dân tộc " << argv[2] << " là : "<< tile_dantoc(SV,key) << "%"; break;
        case 14: cout << "Tỉ lệ giới tính " << argv[2] << " là : "<< tile_gioitinh(SV,key) <<"%"; break;
        // ANSLIYSIS
        case 15: noisinh_analysis(SV,key); break;
        case 16: dantoc_analysis(SV,key); break;
        case 17: namsinh_analysis(SV,key); break;
        case 18: soluongsv_analysis(SV,key); break;
    }
    return 0;
}
