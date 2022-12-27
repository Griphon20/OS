//�������� ���������
#include <iostream>

using namespace std;

int main()
{
    // ������ "������" ���������
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    FILETIME ftCreation,
        ftExit,
        ftKernel,
        ftUser;
    SYSTEMTIME stCreation,
        stExit,
        stKernel,
        stUser;
    PROCESSENTRY32 pe;  //������ ���������� � �������� ��������
    if (Process32First(hSnapshot, &pe)) //����� ������� �������� � ������
    {
        printf("Name obraz                PID   Kol-vo nitei      Prioritet         PID family");
        printf("========================= ===== ================= ================= ============");
        do
        {
            if (!pe.th32ProcessID) continue;    // ������� [System process]
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
                PROCESS_VM_READ,
                FALSE, pe.th32ProcessID);    //�������� ���������� ��������
            GetProcessTimes(hProcess, &ftCreation, &ftExit, &ftKernel, &ftUser);//�������� ��������� ������� ��������
            /////
            FileTimeToSystemTime(&ftCreation, &stCreation);
            FileTimeToSystemTime(&ftExit, &stExit);
            FileTimeToSystemTime(&ftUser, &stUser);
            FileTimeToSystemTime(&ftKernel, &stKernel);
            //            cout<<"creation time   -> "<<stCreation.wHour<<" Hour "<<stCreation.wMinute<<" Min "
            //                <<stCreation.wSecond<<" Sec "<<stCreation.wMilliseconds<<" mSec "<<endl; 
            int now = ((double)stUser.wHour * 3600.0 +
                (double)stUser.wMinute * 60.0 +
                (double)stUser.wSecond +
                (double)stUser.wMilliseconds) / 1000.0;
            int noq = ((double)stKernel.wHour * 3600.0 +
                (double)stKernel.wMinute * 60.0 +
                (double)stKernel.wSecond +
                (double)stKernel.wMilliseconds) / 1000.0;
            cout << "->" << now << "  ->" << noq << endl;
            //float cpu=(now/noq)*100;
            //cout<<"->"<<cpu<<endl;
            /////
            //int MS = ((*((ULONGLONG*)&ftUser)) / (*((ULONGLONG*)&ftKernel)))*100;
            char cPriority[18];
            switch (GetPriorityClass(hProcess)) //�������� ��������� ��������
            {
            case HIGH_PRIORITY_CLASS:
                strcpy(cPriority, "Vishe srednego");
                break;
            case IDLE_PRIORITY_CLASS:
                strcpy(cPriority, "Nizkii");
                break;
            case NORMAL_PRIORITY_CLASS:
                strcpy(cPriority, "Srednii");
                break;
            case REALTIME_PRIORITY_CLASS:
                strcpy(cPriority, "Realnogo vremeni");
                break;
            default:
                strcpy(cPriority, "Visokii");
            }
            CloseHandle(hProcess);
            //������� ���������� � ��������
            printf("%25s%6d%18d%18s%12d\n", pe.szExeFile, pe.th32ProcessID,
                pe.cntUsage, cPriority, pe.th32ParentProcessID);
        } while (Process32Next(hSnapshot, &pe));  //����� ��������� �������� � ������
    }
    else printf("Ne poluchilos' poluchit' informaciu");
    CloseHandle(hSnapshot);
    system("PAUSE");
    return 0;
    getch();
}