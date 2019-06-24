void get_information(LinkedList a) {//管理员录入用户信息
    information*s;
    string n,na,ke,id,tel;
    double money;
    cout << "请录入信息：" << endl << "账号：";
    cin >> n;
    cout << "用户名：";
    cin >> na;
    cout << "密码：";
    cin >> ke;
    cout << "身份证号：";
    cin >> id;
    cout << "电话号码：";
    cin >> tel;
    cout << "账户余额：";
    cin >> money;
    s = new information(n,na,ke,id,tel,money);
    SYSTEMTIME sys;//导入系统当前时间
    GetLocalTime(&sys);
    cout << sys.wYear << "年";
    cout << sys.wMonth << "月";
    cout << sys.wDay << "日";
    cout << sys.wHour << "时";
    cout << sys.wMinute << "分";
    cout << sys.wSecond << "秒";
    cout << sys.wMilliseconds << "毫秒";
    cout << ",星期" << sys.wDayOfWeek << endl;
    cout << endl << "====================================信息录入成功===============================" << endl;
    while (1) {
        char ch;
        a.insertHead(s);
        cout << "是否继续录入信息：" << "1:是" << "   " << "2:否" << endl;
        cin >> ch;
        while (ch != '1'&&ch != '2') {
            cout << "请重新输入是否继续录入信息！" << "1:是" << "  " << "2:否" << endl;
            cin >> ch;
        }
        if (ch == '1') {
            cout << "请输入注册信息：" << endl;
            cout << "账号：" << endl;
            string str111;//定义字符串
            cin >> str111;//输入账号
            int t;//判断账号是否存在
            t = check_num(str111, a);//调用判断账号是否存在的函数
            while (t == 1) {//t=1时
                cout << "账号已存在，请重新注册！" << endl;
                cout << "账号：" << endl;
                cin >> str111;//重新输入账号
                t = check_num(str111, a);
            }
            n = str111;//s的数据域值为新账号
            cout << "用户名：";
            cin >> na;
            cout << "密码：";
            cin >> ke;
            cout << "身份证号:";
            cin >> id;
            cout << "电话号码:";
            cin >> tel;
            cout << "余额:";
            cin >> money;
            cout << endl;
            s = new information(n,na,ke,id,tel,money);
            a.insertHead(s);
            SYSTEMTIME sys;
            GetLocalTime(&sys);
            cout << sys.wYear << "年";
            cout << sys.wMonth << "月";
            cout << sys.wDay << "日";
            cout << sys.wHour << "时";
            cout << sys.wMinute << "分";
            cout << sys.wSecond << "秒";
            cout << sys.wMilliseconds << "毫秒";
            cout << ",星期" << sys.wDayOfWeek << endl;
        }
        else
            break;
        cout << endl << "====================================信息录入成功===============================" << endl;
    }
}