//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <vector.h>
#include <Menus.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TMemo *Memo1;
        TPanel *Panel1;
        TMemo *Memo2;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TPanel *Panel2;
        TPanel *Panel3;
        TMemo *Memo3;
        TPanel *Panel4;
        TButton *Button1;
        TButton *Button2;
        TMemo *Memo4;
        void __fastcall N1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ComboBox4Change(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Memo3Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
class CErrorManager {                                                                                    
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
  class CTimeDelay{                                                      
    public:
     CTimeDelay(double time, double perSecond){
       this->_time = time;
       this->_perSecond=perSecond;
       _changeTime = _time;
    }
      CTimeDelay(double time, double perSecond,bool status){
       this->_time = time;
       this->_perSecond=perSecond;
       this->_statusOfCountdown = status;
       _changeTime = _time;
    }


    void countdown();
    void stopCountdown();
    void renewCountdown();
    void workTimer();//запускает всю работу таймера
 //методы,возвращающие значения
    bool getStatusOfCountdown(){return _statusOfCountdown;}
    void setStatusOfCountdown(bool status) {_statusOfCountdown = status;}
    double getTime(){return _time;}
    double getChangeTime() {return _changeTime;}
    double getPerSecond(){return _perSecond;}
    void setPerSecond(double second) {_perSecond = second;}
    private:
    double _changeTime;
    double _time;
    bool _statusOfCountdown;
    double _perSecond;//коэффициент масштабирования
  };    //класс предназначен для симуляции задержки
   void CTimeDelay :: workTimer () {
  if(_statusOfCountdown) {
        countdown();        }
        else
        renewCountdown();   }

     void CTimeDelay :: renewCountdown () {
      _changeTime = _time;
      _statusOfCountdown=true;   }

  void CTimeDelay:: countdown()
  { if (_statusOfCountdown)    {
      _changeTime-=_perSecond;    }
    if((_changeTime-_perSecond)<0){
       _statusOfCountdown = false;   }
  }
   void CTimeDelay:: stopCountdown()  {
   _statusOfCountdown = false;  }
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CStatisticManager{    //менеджер статистики
       public:
     int getNumberOfTotalRequest(){return _numberOfTotalRequest;}
     int getNumberOfSystemRequest(){return _numberOfSystemRequest;}
     double getTime ()  {return _workTime;                                                                               
    private:
    int _numberOfSystemRequest;
    int _numberOfTotalRequest;
    double _workTime;
};
//---------------------------------------------------------------------------
class CStructureOfScheme{ // структура схемы
       virtual AnsiString connectionInfo() = 0;
};
//---------------------------------------------------------------------------
class CQScheme :public CErrorManager, CStatisticManager,public CStructureOfScheme{
  public:
  void turnOnModel();
 void turnOffModel();
  private:
  bool _isWorking;
};
void CQScheme:: turnOnModel(){
    if(_isWorking==false)
_isWorking = true;
}
void CQScheme:: turnOffModel(){
    if(_isWorking)
_isWorking = false;
}
//---------------------------------------------------------------------------
class CStructureElement{
public:

CStructureElement(AnsiString name){
 this->_name = name;
}
AnsiString messageShow(AnsiString);
void setConnection(AnsiString);
virtual AnsiString connectionInfo();
AnsiString getName(){return _name;}
virtual void setNumberOfConnections (int numberOfConnections) {this->_numbersOfConnections = numberOfConnections;}
void deleteLastConnection();
private:
        AnsiString _name;
        int _numbersOfConnections;
         void turnOnModel();
         void turnOffModel();
        vector <AnsiString> connectTo ;
protected:
AnsiString _myMessage;
};
AnsiString CStructureElement::connectionInfo(){//информация о элементе и его связях
AnsiString result = _name + " связан с : ";
for(int i=0;i<connectTo.size();i++)
result+=connectTo[i]+"  ";
return result;
}
void CStructureElement:: setConnection(AnsiString connect){
connectTo.push_back(connect);
}
AnsiString CStructureElement:: messageShow(AnsiString textFromOutside){
AnsiString message;
message=_name+" : "+textFromOutside;
return message;
}
void CStructureElement :: deleteLastConnection(){
  connectTo.pop_back();
}
//ветка управления
//-----------------------------------------------------------------------------
class CControlSignal;
class CObjectOfControl:public CStructureElement{ //объект управления
    public:
    CObjectOfControl (AnsiString name):CStructureElement(name){
    }
    void setControlSignal(CControlSignal csignal){ *_currentSignal = csignal;}
    private:
    CObjectOfControl();
    protected:
    CControlSignal *_currentSignal;
};
//----------------------------------------------------------------------------
class CControlSignal:public CObjectOfControl{  //управляющий сигнал
   public:
CControlSignal (AnsiString name,bool statusOfSignal):CObjectOfControl(name)
{this->_statusOfSignal=statusOfSignal;}
    bool isStatusBusy();   //если true, то сигнал закрывает
    void setStatusOfSignal(bool);
      private:
             bool _statusOfSignal;//true закрыт, false - открыт
              CControlSignal();
};
  bool CControlSignal:: isStatusBusy(){
 if(_statusOfSignal)
 return true;
return false;
}
void CControlSignal :: setStatusOfSignal(bool status){
 this->_statusOfSignal=status;
}

//----------------------------------------------------------------------------
class CRequest{    public:


  CRequest( AnsiString type)
  {
  this->_priority=0;
  this->_type = type;
  }
  AnsiString getMessage(){return _myMessage;}                                                                                  
  AnsiString getType(){return _type;}
  AnsiString getPriority(){return _priority;}
  void setPriority(int newPriority){_priority = newPriority;}
  private:
   AnsiString _type;
   int _priority;
   CRequest();
   AnsiString _myMessage;
};
//----------------------------------------------------------------------------
class CRequestHandler: public CStructureElement { //обработчик заявок
  public:
    CRequestHandler(AnsiString name):CStructureElement(name){
  }
  virtual void workWithRequest();
  private:
  CRequestHandler();
  protected:
  CRequest *_currentRequest;
};
    void CRequestHandler :: workWithRequest () {
    }
//---------------------------------------------------------------------------
class CReceiver : virtual public CRequestHandler {    //приемник
  public:
  CReceiver (AnsiString name):CRequestHandler(name){
  }
  virtual void setRequest(CRequest *request){this->_currentRequest=request;}
  private:
  CReceiver ();
};
//---------------------------------------------------------------------------
class CTransmitter :virtual public CRequestHandler{    //передатчик
  public:
  CTransmitter (AnsiString name):CRequestHandler(name){
  }
  virtual CRequest* getRequest();
  private:
  CTransmitter();
};

CRequest* CTransmitter:: getRequest() {
  return _currentRequest;
}

//---------------------------------------------------------------------------
class CRandomGenerator {  //генератор чисел
};
//---------------------------------------------------------------------------
class CTransmitterWithPause: public CTransmitter, CRandomGenerator{//передатчик с задержкой
   public:
   CTransmitterWithPause(AnsiString name):CTransmitter(name),CRequestHandler(name){
   }
   double getTime(){return _generationTime;}
   void createTimer();
   getChangeTime() {return _changeTime;}
   getTimeDelay(){return _timeDelay;}
   private:
   CTransmitterWithPause();
   protected:
   double _generationTime;
   double _timeDelay;
   CTimeDelay *_timing;
     double _changeTime;
};
 void CTransmitterWithPause::createTimer() {
 _timing = new CTimeDelay(_generationTime,_timeDelay);
}
//----------------------------------------------------------------------------
class CReqGenerator :public CTransmitterWithPause { //генератор заявок
  public:
        CReqGenerator(AnsiString name,double time,double delay):CTransmitterWithPause(name),CRequestHandler(name)
        {
       this->_generationTime=time;
       this->_timeDelay = delay;
         this->createTimer();
        }
       virtual void workWithRequest();
       int getNumbersOfGenerateReq () {return this->_numbersOfGenerateReq;}
        CRequest createRequest(AnsiString);
  private:
  CReqGenerator();
  int _numbersOfGenerateReq;
};
//определения методов
CRequest CReqGenerator :: createRequest(AnsiString type){
CRequest request (type);
this->_numbersOfGenerateReq++;
return request;
 }
void CReqGenerator::workWithRequest() {
_timing->workTimer();
 _changeTime = _timing->getChangeTime();
//добавить выброс заявки
}
//---------------------------------------------------------------------------
class CDevice: public CTransmitterWithPause , public  CReceiver {  //канал
public:

CDevice(AnsiString name,double processTime , bool hasRequest, double perSecond):CRequestHandler(name),CTransmitterWithPause(name),CReceiver(name){
         this->_hasRequest = hasRequest;
         this->_timeDelay = perSecond;
         this->_generationTime = processTime;
         this->createTimer();
         this->_hasRequest = false;
        }
        void createControlSignal(AnsiString,bool);
        virtual void setRequest(CRequest *);
        CRequest* sendRequest();
        bool isHasRequest();   //проверка на наличие заявки в канале
        //функции доступа
        virtual void workWithRequest();
        CControlSignal getControlSignal() {return *_control;}
        AnsiString showInfo();
private:
       CControlSignal *_control;
        bool _hasRequest;
        CDevice();
};
void CDevice:: createControlSignal(AnsiString name, bool type) {
        _control = new CControlSignal(name, type);
}
void CDevice:: setRequest (CRequest *request) {
  _currentRequest = request;
    this->_hasRequest=true;
    _currentRequest = new CRequest(_currentRequest->getType());
}
AnsiString CDevice:: showInfo(){
 return this->getName()+" начал обработку заявки типа :" + _currentRequest->getType();
}
CRequest* CDevice:: sendRequest () {
    this->_hasRequest=false;
    return this->_currentRequest;
}
bool CDevice:: isHasRequest(){
 if(_hasRequest)
 return true;
return false;
}
void CDevice::workWithRequest() {
_timing->workTimer();
 _changeTime = _timing->getChangeTime();
}
//---------------------------------------------------------------------------
class CProtocolOfWork { //дисциплина обслуживания                                   
};
//----------------------------------------------------------------------------
class CQueue: public CReceiver , public CTransmitter ,public CProtocolOfWork {   //очередь
public:
CQueue(AnsiString name):CRequestHandler(name),CReceiver(name),CTransmitter(name){
}
  void clearQueue();
  void addElementInQueue(CRequest*);
  void endElementQueue();
  void deleteElement();
  CRequest takeFirstElement();
  AnsiString showInfo();
  void createControlSignal(AnsiString,bool);
  bool isEmpty();
  //методы, возвращающие значения
  int getNumbersOfRequest() {return _numbersOfRequest;}
  CControlSignal getControlSignal () {return *_control;}
   int getLengthOfQueue() {return requestQueue.size();}
   CRequest getLastElement() {return requestQueue.back();}
  private:
    CControlSignal *_control;
    CQueue ();
    protected:
    int _numbersOfRequest;
    vector <CRequest> requestQueue;

};
void CQueue:: createControlSignal(AnsiString name, bool type) {
        _control = new CControlSignal(name, type);
}                 //создаем и инициализируем управляющий сигнал
bool CQueue:: isEmpty() {
        if(requestQueue.empty())
        return true;
return false;
}
CRequest CQueue:: takeFirstElement() {
    CRequest request = requestQueue.front();
   requestQueue.erase(requestQueue.begin());
   return request;
}
void CQueue:: clearQueue() {                                 
        requestQueue.clear();
}
AnsiString CQueue:: showInfo(){
 return this->getName()+" содержит заявок : "+requestQueue.size();
};
void CQueue :: addElementInQueue(CRequest *requestOf){
  requestQueue.push_back(*requestOf);
}
void CQueue :: deleteElement(){
  requestQueue.pop_back();
}
//----------------------------------------------------------------------------
class CUnlimitedQueue : public CQueue {
 public:
 CUnlimitedQueue (AnsiString name): CRequestHandler(name),CQueue(name) {
  }
  private:
  CUnlimitedQueue();
};
//----------------------------------------------------------------------------
class CLimitedQueue :public CQueue{
public:
 CLimitedQueue (AnsiString name,int maxNumbersOfRequest): CRequestHandler(name),CQueue(name) {
    this->_maxNumbersOfRequest=maxNumbersOfRequest;
  }
    virtual AnsiString statusOfQueue();
    void  deleteElement();
   bool  isQueueFull();
   AnsiString compareWithVector(CRequest);
private:
        int _maxNumbersOfRequest ;
      CLimitedQueue();
};
AnsiString CLimitedQueue:: statusOfQueue ()
{
 if(this->getLengthOfQueue()==0)
 return "Пусто";
 else if(this->getLengthOfQueue()>=_maxNumbersOfRequest){
 int dif = this->getLengthOfQueue()-_maxNumbersOfRequest;
 for(int i=0;i<dif;i++)
 deleteElement();
 return "Заполнено";
 }
 else
 return "Количество заявок в очереди:"+IntToStr(_maxNumbersOfRequest);
}
void CLimitedQueue :: deleteElement(){
  requestQueue.pop_back();
}
bool CLimitedQueue :: isQueueFull (){
        if(requestQueue.size()==_maxNumbersOfRequest)
        return true;
return false;
}
AnsiString CLimitedQueue::compareWithVector(CRequest request){
  for(int i=0;i<this->requestQueue.size();i++)
  {
  if(requestQueue[i].getType()==request.getType())
  return requestQueue[i].getType();
  }
  return " ";
}
//----------------------------------------------------------------------------
class CGate :public CTransmitter , public CReceiver, public CObjectOfControl{   //клапан
public:
CGate(AnsiString name):CRequestHandler(name),CTransmitter(name),CReceiver(name),CObjectOfControl(name){
  this->_statusOfGate=true;
}
bool isGateOpen();
void onOffGate(bool signal);  //если открыт,то true
AnsiString objectNulling(CRequest*);
virtual void workWithRequest();
private:
bool _statusOfGate;
CGate();
};
void CGate::onOffGate(bool signal){
  if(signal == false)
  _statusOfGate = false;
  else
_statusOfGate=true;
}
AnsiString CGate::objectNulling(CRequest *request){
AnsiString message = "Заявка типа : " + request->getType()+" уничтожена!";
 delete request;
 return message;
}

bool CGate:: isGateOpen() {  //если открыт,то true
 if(_statusOfGate)
 return true;
return false;
}
void CGate::workWithRequest() {
}
//---------------------------------------------------------------------------
 //ветвь контроллеров
class CMassController: public CStructureElement  { //массовый контроллер
   public:
     CMassController(AnsiString name):CStructureElement(name){
     };
        virtual AnsiString chooseGate();
         void createControlSignal(AnsiString,bool);
         void addGate(CGate);
         void deleteLastGate();
         void deleteFirstGate();
         void setIndexElement(int,bool);
         //методы,возвращающие значения
        int getNumbersOfExits() {return this->_gatesForControl.size();}
        CControlSignal getControlSignal () {return *_control;}
 private:
   CMassController();
   CControlSignal *_control;
   protected:
   vector <CGate> _gatesForControl;
};
AnsiString CMassController::chooseGate (){
  for( int i=0;i< _gatesForControl.size();i++)
  if(_gatesForControl[i].isGateOpen())
  return _gatesForControl[i].CObjectOfControl::getName();
}
void CMassController:: createControlSignal(AnsiString name, bool type) {

        _control = new CControlSignal(name, type);
}
void CMassController::setIndexElement(int index,bool status){
  _gatesForControl[index].onOffGate(status);
}
void CMassController::addGate (CGate gateFor){
_gatesForControl.push_back(gateFor);
}
void CMassController::deleteLastGate (){
this->_gatesForControl.pop_back();
}
void CMassController::deleteFirstGate (){
this->_gatesForControl.erase(this->_gatesForControl.begin());
}
//---------------------------------------------------------------------------
class CTotalMassController: public CMassController {
public:
  CTotalMassController(AnsiString name):CMassController(name){
     };
 virtual AnsiString chooseGate();
 AnsiString chooseGate(AnsiString);
 private:
 CTotalMassController();
 };
AnsiString CTotalMassController::chooseGate (){
 }
 AnsiString CTotalMassController::chooseGate (AnsiString value){
    if(value == "1й")
    return this->_gatesForControl[0].CObjectOfControl::getName();
      if(value == "2й")
    return this->_gatesForControl[1].CObjectOfControl::getName();
      if(value == "3й")
    return this->_gatesForControl[2].CObjectOfControl::getName();
      if(value == "4й")
    return this->_gatesForControl[3].CObjectOfControl::getName();
      if(value == "5й")
    return this->_gatesForControl[4].CObjectOfControl::getName();
}
//---------------------------------------------------------------------------
class CAdaptiveController: public CMassController{
 public:
 CAdaptiveController(AnsiString name):CMassController(name){
     };
private:
 CAdaptiveMassController();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

