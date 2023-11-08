#include <iostream>

using namespace std;

struct DSLKD
{
    int data;
    struct DSLKD* next;
};

typedef struct DSLKD* node;//Định nghĩa node là DSLKD cho ngắn gọn

node TaoNode(int x)//tạo node và truyền giá trị
{
    node tam;
    tam = (node)malloc(sizeof(struct DSLKD));//Dùng malloc() cấp phát vùng nhớ
    tam->next = NULL; //Cho tam next trỏ tới rỗng;
    tam->data = x;//gắn giá trị cho node
    return tam;//trả về node mới có giá trị
}

node AddHead(node head, int x)
{
    node tam = TaoNode(x);//node tạm = tạo node gắn với giá trị
    if (head == NULL)
        head = tam;//Head rỗng thì thêm giá trị vào head
    else
    {
        tam->next = head; // trỏ tam next = head hiện tại ví dụ head = 1 = not null
        tam = head;//cho tam = head = 1 ==> tam->next = 2
    }
    return head;
}
node AddAt(node head, int x, int vitri)
{
    if (vitri == 0 || head == NULL)
    {
        head = AddHead(head, x);//Nếu vị trí chèn là 0 hoặc head rỗng thì chèn vào
    }
    else//Nếu không phải 2 điều kiên trên thì dùng v để đếm cho tìm vị trí cần chèn
    {
        int v = 1;
        node p = head; //node p là node phụ
        while (p != NULL && v != vitri)
        {
            p = p->next;//tăng dần node p đến khi tìm thấy p rỗng
            ++v;//tăng dần v đến khi đến đúng vị trí
        }
        if (v != vitri)
        {
            //Nếu duyệt hết DSLK mà vẫn chưa đến vị trí cần chèn thì mặc định chèn ở cuối danh sách
            //Nếu không muốn chèn thì thông báo vị trí chèn không hợp lệ
            //head = AddTail(head, x);
            cout<<" Vi tri chen vuot qua vi tri cuoi cung!"<<endl;
        }
        else//Neu v = vitri can tim
        {
            node tam = TaoNode(x);///Goi ham TaoNode de khoi tao node tam co next tro toi NULL va gia tri la x
            tam->next = p->next;//gan tam->next = p->next ==> vi tri v hoac p == NULL
            p->next = tam;//gan gia tri tam vao p->next
        }
    }
    return head;
}

node AddTail(node head, int x)
{
    node tam, p;//khai bao 2 node tam va p
    tam = TaoNode(x);//Goi ham TaoNode de khoi tao node tam co next tro toi NULL va gia tri la x
    if (head == NULL)
    {
        head = tam;//Neu DSLK co head NULL thi gan head = node tam
    }
    else
    {
        p = head;//Khoi tao p tro toi head
        while (p->next != NULL)
        {
            p = p->next;//Duyet DSLK tu dau den khi nao node cuoi = NULL thi ngung 
        }
        p->next = tam;//gan next node cuoi = node tam thi khi do tam la node cuoi
    }
    return head;
}

node DelHead(node head)
{
    if (head == NULL)
    {
        cout << "\nDSLK rong, khong co gi de xoa" << endl;
    }
    else
    {
        head = head->next;//Tang tu head 1 => head next 2 ==> head 1 bi loai khoi dslk
    }
    return head;
}

node DelTail(node head)
{
    if (head == NULL || head->next == NULL)//Neu head rong hoac head next rong thi goi ham xoa head
    {
        return DelHead(head);
    }
    node p = head;
    while (p->next->next != NULL)//Neu cach p 2 lan khac NULL
    {
        p = p->next; // tang p dan den khi nao dieu kien tren sai
    }
    //p->next->next = NULL
    p->next = p->next->next; // vi du 3 = 4(NULL) ==> 3 = NULL
        //p->next = NULL cach viet 2
        return head;
}

node DelAt(node head, int v)
{
    if (v == 0 || head == NULL || head->next == NULL)
    {
        head = DelHead(head);
    }
    else // Tuong tu nhu AddAt
    {
        int k = 1;
        node p = head;
        while (p->next->next != NULL && k != v)
        {
            p = p->next;
            ++k;
        }
        if (k != v)
        {
            head = DelTail(head);
            //cout<<"Vi tri vuot qua vi tri cuoi cung";
        }
        else
        {
            p->next = p->next->next;
            //p->next = NULL
        }
    }
    return head;
}

int Get(node head, int i)//index
{
    int v = 0;//vi tri = 0
    node p = head;
    while (p != NULL && v != i)
    {
        p = p->next;//Duyet dan p den khi gap node = NULL
    }
    return p->data;
}

int Search(node head, int x)//Tim Kiem
{
    int v = 0;
    for (node p = head; p != NULL; p = p->next)//for(0; den khi het NULL; p->next tang dan)
    {
        if (p->data == x) //neu p->data = x ==> tra ve vi tri
        {
            return v;
        }
        ++v;
    }
    return -1;
}

void xuat(node head)
{
    for (node p = head; p != NULL; p = p->next)
    {
        cout <<" "<< p->data<<" ";
    }
}

node InitHead()//Tao head rong
{
    node head;
    head = NULL;
    return head;
}

int Length(node head)//Tim do dai cua DSLK
{
    int length = 0;
    for (node p = head; p != NULL; p = p->next)
    {
        ++length;
    }
    return length;
}

node Input()
{
    node head = InitHead();//Tao head rong
    int n, x;
    do
    {
        cout << "\nNhap so luong phan tu: " << endl;
        cin >> n;
    } while (n <= 0);//try catch de nguoi dung khong nhap so am hoac 0
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao gia tri: " << endl;
        cin >> x;
        head = AddTail(head, x);
    }
    return head;
}

int main()
{
    cout << "------------------\n";
    cout << "==Tao mot Danh sach lien ket==" << endl;
    node head = Input();
    xuat(head);

    cout << "\n==Them 1 phan tu vao DSLK==" << endl;
    int x,v;
    cout << "Nhap vao phan tu can them: " << endl;
    cin >> x;
    cout << "Nhap vao vi tri can them: " << endl;
    cin >> v;
    head = AddAt(head, x, v);//AddHead or AddTail
    xuat(head);

    cout << "\n==Xoa 1 phan tu khoi DSLK==" << endl;
    cout << "Nhap vao vi tri can xoa: " << endl;
    cin >> v;
    head = DelAt(head, v);
    xuat(head);

    cout << "\n==Tim Kiem 1 phan tu trong DSLK==" << endl;
    cout << "Nhap vao phan tu can Tim kiem: " << endl;
    cin >> x;
    int i = Search(head, x);
    cout << "\nTim thay tai chi so " << i+1;
}
