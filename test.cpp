void get_information(LinkedList a) {//����Ա¼���û���Ϣ
    information*s;
    string n,na,ke,id,tel;
    double money;
    cout << "��¼����Ϣ��" << endl << "�˺ţ�";
    cin >> n;
    cout << "�û�����";
    cin >> na;
    cout << "���룺";
    cin >> ke;
    cout << "���֤�ţ�";
    cin >> id;
    cout << "�绰���룺";
    cin >> tel;
    cout << "�˻���";
    cin >> money;
    s = new information(n,na,ke,id,tel,money);
    SYSTEMTIME sys;//����ϵͳ��ǰʱ��
    GetLocalTime(&sys);
    cout << sys.wYear << "��";
    cout << sys.wMonth << "��";
    cout << sys.wDay << "��";
    cout << sys.wHour << "ʱ";
    cout << sys.wMinute << "��";
    cout << sys.wSecond << "��";
    cout << sys.wMilliseconds << "����";
    cout << ",����" << sys.wDayOfWeek << endl;
    cout << endl << "====================================��Ϣ¼��ɹ�===============================" << endl;
    while (1) {
        char ch;
        a.insertHead(s);
        cout << "�Ƿ����¼����Ϣ��" << "1:��" << "   " << "2:��" << endl;
        cin >> ch;
        while (ch != '1'&&ch != '2') {
            cout << "�����������Ƿ����¼����Ϣ��" << "1:��" << "  " << "2:��" << endl;
            cin >> ch;
        }
        if (ch == '1') {
            cout << "������ע����Ϣ��" << endl;
            cout << "�˺ţ�" << endl;
            string str111;//�����ַ���
            cin >> str111;//�����˺�
            int t;//�ж��˺��Ƿ����
            t = check_num(str111, a);//�����ж��˺��Ƿ���ڵĺ���
            while (t == 1) {//t=1ʱ
                cout << "�˺��Ѵ��ڣ�������ע�ᣡ" << endl;
                cout << "�˺ţ�" << endl;
                cin >> str111;//���������˺�
                t = check_num(str111, a);
            }
            n = str111;//s��������ֵΪ���˺�
            cout << "�û�����";
            cin >> na;
            cout << "���룺";
            cin >> ke;
            cout << "���֤��:";
            cin >> id;
            cout << "�绰����:";
            cin >> tel;
            cout << "���:";
            cin >> money;
            cout << endl;
            s = new information(n,na,ke,id,tel,money);
            a.insertHead(s);
            SYSTEMTIME sys;
            GetLocalTime(&sys);
            cout << sys.wYear << "��";
            cout << sys.wMonth << "��";
            cout << sys.wDay << "��";
            cout << sys.wHour << "ʱ";
            cout << sys.wMinute << "��";
            cout << sys.wSecond << "��";
            cout << sys.wMilliseconds << "����";
            cout << ",����" << sys.wDayOfWeek << endl;
        }
        else
            break;
        cout << endl << "====================================��Ϣ¼��ɹ�===============================" << endl;
    }
}