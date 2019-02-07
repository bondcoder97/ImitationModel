//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{}
//---------------------------------------------------------------------------
//клапаны
CGate k1("K1");
CGate k2("K2");
CGate k3("K3");
CGate k4("K4");
CGate k5("K5");
CGate k6("K6");
CGate k9("K9");
CGate k10("K10");
CGate k11("K11");
CGate k12("K12");
CGate k13("K13");
CGate k14("K14");
CGate k15("K15");
CGate k16("K16");
CGate k19("K19");
CGate k20("K20");
CGate k21("K21");
CGate k22("K22");
CGate k23("K23");
CGate k24("K24");
CGate k25("K25");
CGate k26("K26");
CGate k32("K32");
//конечные очереди
CLimitedQueue och1("ОЧ1",5);
CLimitedQueue och3("ОЧ3",10);
CLimitedQueue och4("ОЧ4",10);
CLimitedQueue och5("ОЧ5",10);
CLimitedQueue och6("ОЧ6",10);
CLimitedQueue och7("ОЧ7",10);
CLimitedQueue och8("ОЧ8",8);
CLimitedQueue NMD2("НМД2",5);
//бесконечные очереди
CUnlimitedQueue och2("ОЧ2");
CUnlimitedQueue och9("ОЧ9");
CUnlimitedQueue och10("ОЧ10");
CUnlimitedQueue och11("ОЧ11");
CUnlimitedQueue och12("ОЧ12");
CUnlimitedQueue och13("ОЧ13");
CUnlimitedQueue NMD1("НМД1");
//контроллеры
CTotalMassController KM1 ("KM1");
CAdaptiveController  KA1("KA1");
//объявление генераторов
CReqGenerator *query1;
CReqGenerator *query2;
CReqGenerator *query3;
CReqGenerator *query4;
CReqGenerator *query5;
//объявления каналов
CDevice *terminal1;
CDevice *terminal2;
CDevice *terminal3;
CDevice *processor;
CDevice *PO1;
CDevice *PO2;
CDevice *PO3;
CDevice *PO4;
CDevice *PO5;
double seconds = 0;
double oneTick;
AnsiString comparedValue;
bool indicatorForMe = false;
float numbersOfSuccessRequest = 0;
float numbersOfCrashRequest = 0;
float requestPotential;//вероятность
float totalNumbersOfRequest = 0;
CControlSignal signal1("сигнал1",false);
CControlSignal signal2("сигнал2",true);
void timerProcess (CTimeDelay *objectTime , TEdit *showTimeEdit)  {
  objectTime->workTimer();
  showTimeEdit->Text = FloatToStr(objectTime->getChangeTime());
}    // объект и эдит

void __fastcall TForm1::N1Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------
 void setInitializeConnections() {
//клапаны
   k1.CObjectOfControl::setConnection("Запрос 5");
   k1.CObjectOfControl::setConnection("ОЧ7");
   k1.CObjectOfControl::setConnection("Выход");
   k2.CObjectOfControl::setConnection("Запрос 4");
   k2.CObjectOfControl::setConnection("ОЧ6");
   k2.CObjectOfControl::setConnection("Выход");
   k3.CObjectOfControl::setConnection("Запрос 3");
   k3.CObjectOfControl::setConnection("ОЧ5");
   k3.CObjectOfControl::setConnection("Выход");
   k4.CObjectOfControl::setConnection("Запрос 2");
   k4.CObjectOfControl::setConnection("ОЧ4");
   k4.CObjectOfControl::setConnection("Выход");
   k5.CObjectOfControl::setConnection("Запрос 1");
   k5.CObjectOfControl::setConnection("ОЧ3");
   k5.CObjectOfControl::setConnection("Выход");
   k6.CObjectOfControl::setConnection("ОЧ7");
   k6.CObjectOfControl::setConnection("ОЧ6");
   k6.CObjectOfControl::setConnection("ОЧ5");
   k6.CObjectOfControl::setConnection("ОЧ4");
   k6.CObjectOfControl::setConnection("ОЧ3");
   k3.CObjectOfControl::setConnection("К10");
   k3.CObjectOfControl::setConnection("К9");
   k9.CObjectOfControl::setConnection("K6");
   k9.CObjectOfControl::setConnection("Терминал 1");
   k10.CObjectOfControl::setConnection("K6");
   k10.CObjectOfControl::setConnection("Терминал 2");
   k11.CObjectOfControl::setConnection("Терминал 3");
   k11.CObjectOfControl::setConnection("Терминал 1");
   k11.CObjectOfControl::setConnection("Терминал 2");
   k11.CObjectOfControl::setConnection("НМД1");
   k11.CObjectOfControl::setConnection("К13");
   k11.CObjectOfControl::setConnection("К12");
   k11.CObjectOfControl::setConnection("К14");
   k12.CObjectOfControl::setConnection("К11");
   k12.CObjectOfControl::setConnection("К16");
   k12.CObjectOfControl::setConnection("ОЧ1");
   k13.CObjectOfControl::setConnection("К11");
   k13.CObjectOfControl::setConnection("К15");
   k13.CObjectOfControl::setConnection("ОЧ8");
   k14.CObjectOfControl::setConnection("ОЧ2");
   k14.CObjectOfControl::setConnection("К11");
   k15.CObjectOfControl::setConnection("К13");
   k15.CObjectOfControl::setConnection("ОЧ8");
   k16.CObjectOfControl::setConnection("К12");
   k16.CObjectOfControl::setConnection("ОЧ1");
   k19.CObjectOfControl::setConnection("К20");
   k19.CObjectOfControl::setConnection("НМД2");
   k19.CObjectOfControl::setConnection("Процессор");
   k20.CObjectOfControl::setConnection("Процессор");
   k20.CObjectOfControl::setConnection("К19");
   k20.CObjectOfControl::setConnection("НМД1");
   k21.CObjectOfControl::setConnection("НМД2");
   k21.CObjectOfControl::setConnection("К22");
   k21.CObjectOfControl::setConnection("К23");
   k21.CObjectOfControl::setConnection("К24");
   k21.CObjectOfControl::setConnection("К25");
   k21.CObjectOfControl::setConnection("К26");
   k22.CObjectOfControl::setConnection("К21");
    k22.CObjectOfControl::setConnection("ОЧ9");
   k23.CObjectOfControl::setConnection("К21");
      k23.CObjectOfControl::setConnection("ОЧ10");
   k24.CObjectOfControl::setConnection("К21");
    k24.CObjectOfControl::setConnection("ОЧ11");
   k25.CObjectOfControl::setConnection("К21");
      k25.CObjectOfControl::setConnection("ОЧ12");

   k26.CObjectOfControl::setConnection("К21");
   k26.CObjectOfControl::setConnection("ОЧ13");
   k32.CObjectOfControl::setConnection("К11");
   k32.CObjectOfControl::setConnection("ПО - 1");
   k32.CObjectOfControl::setConnection("ПО - 2");
   k32.CObjectOfControl::setConnection("ПО - 3");
   k32.CObjectOfControl::setConnection("ПО - 4");
   k32.CObjectOfControl::setConnection("ПО - 5");
//генераторы
  query1->setConnection("ОЧ3");
  query1->setConnection("К5");
  query2->setConnection("ОЧ4");
  query2->setConnection("К4");
  query3->setConnection("ОЧ5");
  query3->setConnection("К3");
  query4->setConnection("ОЧ6");
  query4->setConnection("К2");
  query5->setConnection("ОЧ7");
  query5->setConnection("К1");
//каналы
terminal1->setConnection("K9");
terminal1->setConnection("K11");
terminal2->setConnection("K10");
terminal2->setConnection("K11");
terminal3->setConnection("ОЧ7");
terminal3->setConnection("K11");
processor->setConnection("ОЧ1");
processor->setConnection("K19");
processor->setConnection("К20");
processor->setConnection("ОЧ8");
PO1->setConnection("К32");
PO1->setConnection("ОЧ9");
PO2->setConnection("К32");
PO2->setConnection("ОЧ10");
PO3->setConnection("К32");
PO3->setConnection("ОЧ11");
PO4->setConnection("К32");
PO4->setConnection("ОЧ12");
PO5->setConnection("К32");
PO5->setConnection("ОЧ13");
//очереди
och1.setConnection("K12");
och1.setConnection("K16");
och1.setConnection("Процессор");
och2.setConnection("K14");
och2.setConnection("Выход");
och3.setConnection("K5");
och3.setConnection("Запрос 1");
och3.setConnection("К6");
och4.setConnection("Запрос 2");
och4.setConnection("К4");
och4.setConnection("К6");
och5.setConnection("Запрос 3");
och5.setConnection("К3");
och5.setConnection("К6");
och6.setConnection("Запрос 4");
och6.setConnection("К6");
och6.setConnection("К2");
och7.setConnection("K1");
och7.setConnection("Запрос 5");
och7.setConnection("Терминал 3");
och8.setConnection("K13");
och8.setConnection("К15");
och8.setConnection("Процессор");
och9.setConnection("ПО - 1");
och9.setConnection("К22");
och10.setConnection("ПО - 2");
och10.setConnection("К23");
och11.setConnection("ПО - 3");
och11.setConnection("К24");
och12.setConnection("ПО - 4");
och12.setConnection("К25");

och13.setConnection("ПО - 5");
och13.setConnection("К26");
NMD1.setConnection("K11");
NMD1.setConnection("K20");
NMD2.setConnection("K19");
NMD2.setConnection("K21");
}
void createObjects(double oneTick) {
 query1 = new CReqGenerator("Запрос 1",StrToFloat(Form2->Edit2->Text),oneTick);
 query2 = new CReqGenerator("Запрос 2",StrToFloat(Form2->Edit3->Text),oneTick);
 query3 = new CReqGenerator("Запрос 3",StrToFloat(Form2->Edit4->Text),oneTick);
 query4 = new CReqGenerator("Запрос 4",StrToFloat(Form2->Edit5->Text),oneTick);
 query5 = new CReqGenerator("Запрос 5",StrToFloat(Form2->Edit6->Text),oneTick);
 terminal1=new CDevice("Терминал 1",StrToFloat(Form2->Edit7->Text),false,oneTick);
 terminal2=new CDevice("Терминал 2",StrToFloat(Form2->Edit8->Text),false,oneTick);
 terminal3=new CDevice("Терминал 3",StrToFloat(Form2->Edit9->Text),false,oneTick);
 processor=new CDevice("Процессор",StrToFloat(Form2->Edit10->Text),false,oneTick);;
 PO1=new CDevice("ПО - 1",StrToFloat(Form2->Edit11->Text),false,oneTick);
 PO2=new CDevice("ПО - 2",StrToFloat(Form2->Edit12->Text),false,oneTick);
 PO3=new CDevice("ПО - 3",StrToFloat(Form2->Edit13->Text),false,oneTick);
 PO4=new CDevice("ПО - 4",StrToFloat(Form2->Edit14->Text),false,oneTick);
 PO5=new CDevice("ПО - 5",StrToFloat(Form2->Edit15->Text),false,oneTick);
}  //создает объекты генераторов и каналов
//устанавливаем соединения
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{ // площадка для построения Q-схемы
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
++seconds;
 oneTick = StrToFloat(Form2->Edit1->Text);
 if(Timer1->Tag==2)
 {
  createObjects(oneTick);
 setInitializeConnections();

           indicatorForMe=true;
           CRequest req1("1й");
           CRequest req2("2й");
           CRequest req3("3й");
           CRequest req4("4й");
           CRequest req5("5й");
           NMD2.addElementInQueue(&req1);
           NMD2.addElementInQueue(&req2);
           NMD2.addElementInQueue(&req3);
           NMD2.addElementInQueue(&req4);
           NMD2.addElementInQueue(&req5);
 Timer1->Tag=1;
 }
query1->workWithRequest();
Label2->Caption="До генерации заявки "+FloatToStr(query1->getChangeTime())+" секунд(ы).";
query2->workWithRequest();
Label3->Caption="До генерации заявки "+FloatToStr(query2->getChangeTime())+" секунд(ы).";
query3->workWithRequest();
Label4->Caption="До генерации заявки "+FloatToStr(query3->getChangeTime())+" секунд(ы).";
query4->workWithRequest();
Label5->Caption="До генерации заявки "+FloatToStr(query4->getChangeTime())+" секунд(ы).";
query5->workWithRequest();
Label6->Caption="До генерации заявки "+FloatToStr(query5->getChangeTime())+" секунд(ы).";
Label1->Caption="Программа проработала "+FloatToStr(seconds)+" Тиков"+" ("+FloatToStr(oneTick*seconds)+" симулированных секунд)";
Label35->Caption=FloatToStr(totalNumbersOfRequest);
//------------------------------------------------------ветвь 1го генератора
if((query1->getChangeTime()-query1->getTimeDelay())<=0)

        if(och3.isQueueFull()) {
        CRequest request1 = query1->createRequest("1й");
                totalNumbersOfRequest++;
                k5.onOffGate(true);
                Memo3->Lines->Add( k5.objectNulling(&request1) );
                }
        else
           {
           CRequest request1 = query1->createRequest("1й");
            k5.onOffGate(false);
            totalNumbersOfRequest++;
            och3.addElementInQueue(&request1);
            Memo2->Lines->Add(och3.showInfo());
           }
//----------------------------------------------ветвь второго генератора
if((query2->getChangeTime()-query2->getTimeDelay())<=0)
        if(och4.isQueueFull()) {
        CRequest request1 = query2->createRequest("2й");
         totalNumbersOfRequest++;
                k4.onOffGate(true);
                Memo3->Lines->Add( k4.objectNulling(&request1) );
                }
        else
           {
           CRequest request1 = query2->createRequest("2й");
            k4.onOffGate(false);
             totalNumbersOfRequest++;
            och4.addElementInQueue(&request1);
            Memo2->Lines->Add(och4.showInfo());
           }
//--------------------------------------------------------ветвь третьего генератора
           if((query3->getChangeTime()-query3->getTimeDelay())<=0)
        if(och5.isQueueFull()) {
        CRequest request1 = query3->createRequest("3й");
                k3.onOffGate(true);
                 totalNumbersOfRequest++;
        Memo3->Lines->Add( k3.objectNulling(&request1) );
               }
        else
           {

           CRequest request1 = query3->createRequest("3й");
            totalNumbersOfRequest++;
            k3.onOffGate(false);
            och5.addElementInQueue(&request1);
              Memo2->Lines->Add(och5.showInfo());
           }
//ветвь четвертого генератора---------------------------------------------
           if((query4->getChangeTime()-query4->getTimeDelay())<=0)
        if(och6.isQueueFull()) {
        CRequest request1 = query4->createRequest("4й");
         totalNumbersOfRequest++;
                k2.onOffGate(true);
                Memo3->Lines->Add( k2.objectNulling(&request1) );
                }
        else
           {
           CRequest request1 = query4->createRequest("4й");
            totalNumbersOfRequest++;
            k2.onOffGate(false);
            och6.addElementInQueue(&request1);
              Memo2->Lines->Add(och6.showInfo());
           }
//-----------------------------------------------ветвь пятого генератора
    if((query5->getChangeTime()-query5->getTimeDelay())<=0)

        if(och7.isQueueFull()) {
        CRequest request1 = query4->createRequest("5й");
         totalNumbersOfRequest++;
                k1.onOffGate(true);
                Memo3->Lines->Add( k1.objectNulling(&request1) );
                }
        else
           {
           CRequest request1 = query5->createRequest("5й");
            totalNumbersOfRequest++;
            k1.onOffGate(false);
            och7.addElementInQueue(&request1);
              Memo2->Lines->Add(och7.showInfo());
           }
//-----------------------------------------------------отлично работающая часть
if(!och3.isEmpty()||!och4.isEmpty()|| !och5.isEmpty()||!och6.isEmpty()) {
        k6.onOffGate(true);
           KA1.addGate(k9);
           KA1.addGate(k10);
   if(!och3.isEmpty()) {
                if(KA1.chooseGate()=="K9"){
                        if(terminal1->isHasRequest()==false){
                                 if(!och3.isEmpty())   {
                                 terminal1->setRequest(&och3.takeFirstElement());
                                 Memo2->Lines->Add(och3.showInfo());
                                 Memo1->Lines->Add(terminal1->showInfo());
                                 KA1.setIndexElement(0,false);
                          }
                        }
                }
        }
                       if(KA1.chooseGate()=="K10"){
                        if(terminal2->isHasRequest()==false){
                                if(!och3.isEmpty())   {
                                terminal2->setRequest(&och3.takeFirstElement());
                                Memo2->Lines->Add(och3.showInfo());
                                Memo1->Lines->Add(terminal2->showInfo());
                                KA1.setIndexElement(1,false);
                                }
                        }
             }
//-----------------------------------------------------------------------------
     if(!och4.isEmpty()) {
                if(KA1.chooseGate()=="K9"){
                        if(terminal1->isHasRequest()==false){
                                 if(!och4.isEmpty())   {
                                 terminal1->setRequest(&och4.takeFirstElement());
                                 Memo2->Lines->Add(och4.showInfo());
                                 Memo1->Lines->Add(terminal1->showInfo());
                                 KA1.setIndexElement(0,false);
                          }    }          }        }
                       if(KA1.chooseGate()=="K10"){
                        if(terminal2->isHasRequest()==false){
                                if(!och4.isEmpty())   {
                                terminal2->setRequest(&och4.takeFirstElement());
                                Memo2->Lines->Add(och4.showInfo());
                                Memo1->Lines->Add(terminal2->showInfo());
                                KA1.setIndexElement(1,false);
                                }
                         }
              }
//-----------------------------------------------------------------------------
  if(!och5.isEmpty()) {
                if(KA1.chooseGate()=="K9"){
                        if(terminal1->isHasRequest()==false){
                                 if(!och5.isEmpty())   {
                                 terminal1->setRequest(&och5.takeFirstElement());
                                 Memo2->Lines->Add(och5.showInfo());
                                 Memo1->Lines->Add(terminal1->showInfo());
                                 KA1.setIndexElement(0,false);
                          }       }       }       }
                       if(KA1.chooseGate()=="K10"){
                        if(terminal2->isHasRequest()==false){
                                if(!och5.isEmpty())   {
                                terminal2->setRequest(&och5.takeFirstElement());
                                Memo2->Lines->Add(och5.showInfo());
                                Memo1->Lines->Add(terminal2->showInfo());
                                KA1.setIndexElement(1,false);
                                }
                         }
              }
//---------------------------------------------------------------------------
  if(!och6.isEmpty()) {
                if(KA1.chooseGate()=="K9"){
                        if(terminal1->isHasRequest()==false){
                                 if(!och6.isEmpty())   {
                                 terminal1->setRequest(&och6.takeFirstElement());
                                 Memo2->Lines->Add(och6.showInfo());
                                 Memo1->Lines->Add(terminal1->showInfo());
                                 KA1.setIndexElement(0,false);
                          }      }      }      }
                       if(KA1.chooseGate()=="K10"){
                        if(terminal2->isHasRequest()==false){
                                if(!och6.isEmpty())   {
                                terminal2->setRequest(&och6.takeFirstElement());
                                Memo2->Lines->Add(och6.showInfo());
                                Memo1->Lines->Add(terminal2->showInfo());
                                KA1.setIndexElement(1,false);
                                }               }              }

 }//закрывает условие с очередями
//----------------------------------------------------------очереди - терминалы
if(!och7.isEmpty()){
   if(terminal3->isHasRequest()==false){
                                if(!och7.isEmpty())   {
                                terminal3->setRequest(&och7.takeFirstElement());
                                Memo2->Lines->Add(och7.showInfo());
                                Memo1->Lines->Add(terminal3->showInfo());
                                }
                         }
                }
if(terminal1->isHasRequest()||terminal2->isHasRequest()||terminal3->isHasRequest()) {
 k11.onOffGate(true);
  k12.onOffGate(true);
   if(terminal1->isHasRequest()) {
        terminal1->workWithRequest();
        Label13->Caption=terminal1->getChangeTime();
//--------------------------------------------------------------------------------
        if(terminal1->getChangeTime()==0||(terminal1->getChangeTime()-terminal1->getTimeDelay())<0)
        {
                       if(och1.isQueueFull())  {
                        Memo3->Lines->Add(k16.objectNulling(terminal1->sendRequest()));
                        KA1.setIndexElement(0,true);

                        }
                        else
                        {
                        och1.addElementInQueue(terminal1->sendRequest());
                        Memo2->Lines->Add(och1.showInfo());
                        KA1.setIndexElement(0,true);

                        }
        }
       }//закрывает блок первого терминала
//-----------------------------------------------------------------------------
 if(terminal2->isHasRequest()) {
        terminal2->workWithRequest();
        Label14->Caption=terminal2->getChangeTime();
//--------------------------------------------------------------------------------
        if(terminal2->getChangeTime()==0||(terminal2->getChangeTime()-terminal2->getTimeDelay())<0)
        {
                      if(och1.isQueueFull())  {
                 Memo3->Lines->Add(k16.objectNulling(terminal2->sendRequest()));
                        KA1.setIndexElement(1,true);
                        }
                        else
                        {
                        och1.addElementInQueue(terminal2->sendRequest());
                        Memo1->Lines->Add(och1.showInfo());
                        KA1.setIndexElement(1,true);
                        }
        }
       }//закрывает блок второго терминала
  if(terminal3->isHasRequest()) {
        terminal3->workWithRequest();
        Label15->Caption=terminal3->getChangeTime();
//--------------------------------------------------------------------------------
        if(terminal3->getChangeTime()==0||(terminal3->getChangeTime()-terminal3->getTimeDelay())<0)
        {
                        if(och1.isQueueFull())  {
               Memo3->Lines->Add(k16.objectNulling(terminal3->sendRequest()));
                        }
                        else
                        {
                        och1.addElementInQueue(terminal3->sendRequest());
                        Memo2->Lines->Add(och1.showInfo());
                        }        }
       }//закрывает блок третьего терминала
}//закрывает блок с терминалами
 if(!och1.isEmpty()) {
        if(!processor->isHasRequest())
        {
          processor->setRequest(&och1.takeFirstElement());
          Memo1->Lines->Add(processor->showInfo());
          Memo2->Lines->Add(och1.showInfo());
        }
 }
//---------------------------------------------------------------------------
   if(processor->isHasRequest())
   {
      processor->workWithRequest();
      Label19->Caption=processor->getChangeTime();
      k20.onOffGate(true);
      if(processor->getChangeTime()==0||(processor->getChangeTime()-processor->getTimeDelay())<0)
      {
      NMD1.addElementInQueue(processor->sendRequest());
      Memo2->Lines->Add(NMD1.showInfo());
       }
   }
   if(!NMD1.isEmpty()){
     k13.onOffGate(true);
                if(och8.isQueueFull()) {
                k15.onOffGate(true);
                Memo3->Lines->Add(k15.objectNulling(&NMD1.takeFirstElement()));
                }
                else
                {
                  och8.addElementInQueue(&NMD1.takeFirstElement());
                  Memo2->Lines->Add(och8.showInfo());
                }

   }
if(processor->isHasRequest()&&!och8.isEmpty()){
        k19.onOffGate(true);
        k21.onOffGate(true);
        if(indicatorForMe == true){
        KM1.addGate(k22);
        KM1.addGate(k23);
        KM1.addGate(k24);
        KM1.addGate(k25);
        KM1.addGate(k26);
        indicatorForMe=false;
}
   if((processor->getChangeTime()-processor->getTimeDelay())<=0){
         CRequest *requestFromProcessor = processor->sendRequest();
          comparedValue = NMD2.compareWithVector(*requestFromProcessor);
          delete requestFromProcessor;
          AnsiString valueForSwitch = KM1.chooseGate(comparedValue);
           if(valueForSwitch == "K22") {
           k22.onOffGate(true);
           och9.addElementInQueue(new CRequest("1й"));
          }
           if(valueForSwitch == "K23") {
           k23.onOffGate(true);
           och10.addElementInQueue(new CRequest("2й"));
           }
           if(valueForSwitch == "K24") {
           k24.onOffGate(true);
           och11.addElementInQueue(new CRequest("3й"));
           }
           if(valueForSwitch == "K25") {
           k25.onOffGate(true);
           och12.addElementInQueue(new CRequest("4й"));
           }
           if(valueForSwitch == "K26") {
           k26.onOffGate(true);
           och13.addElementInQueue(new CRequest("5й"));
           }
      }
}
//---------------------Хороший код!---------------------------------------------
//------------------------------------------------------------------------------
if(!och11.isEmpty()||!och12.isEmpty()||!och13.isEmpty()||!och9.isEmpty()||!och10.isEmpty()){
k32.onOffGate(true);
if(!och9.isEmpty()) {
        if(PO1->isHasRequest()==false)
        {
         PO1->setRequest(&och9.takeFirstElement());
         Memo1->Lines->Add(PO1->showInfo());
         Memo2->Lines->Add(och9.showInfo());
        }
}
if(!och10.isEmpty()) {
        if(PO2->isHasRequest()==false)
        {
         PO2->setRequest(&och10.takeFirstElement());
        Memo1->Lines->Add(PO2->showInfo());
         Memo2->Lines->Add(och10.showInfo());
        }
}
if(!och11.isEmpty()) {
        if(PO3->isHasRequest()==false)
        {
         PO3->setRequest(&och11.takeFirstElement());
         Memo1->Lines->Add(PO3->showInfo());
         Memo2->Lines->Add(och11.showInfo());
        }
}
if(!och12.isEmpty()) {
        if(PO4->isHasRequest()==false)
        {
         PO4->setRequest(&och12.takeFirstElement());
         Memo1->Lines->Add(PO4->showInfo());
         Memo2->Lines->Add(och12.showInfo());
        }
}
if(!och13.isEmpty()) {
        if(PO5->isHasRequest()==false)
        {
         PO5->setRequest(&och13.takeFirstElement());
         Memo1->Lines->Add(PO5->showInfo());
         Memo2->Lines->Add(och13.showInfo());
        }
}
} //закрывает блок каналов ПО
if(PO1->isHasRequest()||PO2->isHasRequest()||PO3->isHasRequest()||PO4->isHasRequest()||PO5->isHasRequest()){
k14.onOffGate(true);
 if(PO1->isHasRequest()) {
        PO1->workWithRequest();
        Label26->Caption=PO1->getChangeTime();
        if(PO1->getChangeTime()==0||(PO1->getChangeTime()-PO1->getTimeDelay())<0)
        {
                        och2.addElementInQueue(PO1->sendRequest());
                        Memo2->Lines->Add(och2.showInfo()); }
       }//закрывает блок первого ПО
        if(PO2->isHasRequest()) {
        PO2->workWithRequest();
        Label27->Caption=PO1->getChangeTime();
        if(PO2->getChangeTime()==0||(PO2->getChangeTime()-PO2->getTimeDelay())<0)
        {
                        och2.addElementInQueue(PO2->sendRequest());
                        Memo2->Lines->Add(och2.showInfo());
        }
       }//закрывает блок второго ПО
        if(PO3->isHasRequest()) {
        PO3->workWithRequest();
        Label28->Caption=PO3->getChangeTime();
        if(PO3->getChangeTime()==0||(PO3->getChangeTime()-PO3->getTimeDelay())<0)
        {
                        och2.addElementInQueue(PO3->sendRequest());
                        Memo2->Lines->Add(och2.showInfo());
        }
       }//закрывает блок третьего ПО
        if(PO4->isHasRequest()) {
        PO4->workWithRequest();
        Label29->Caption=PO4->getChangeTime();
        if(PO4->getChangeTime()==0||(PO4->getChangeTime()-PO4->getTimeDelay())<0)
        {
                        och2.addElementInQueue(PO4->sendRequest());
                        Memo2->Lines->Add(och2.showInfo());
        }
       }//закрывает блок четвертого ПО
        if(PO5->isHasRequest()) {
        PO5->workWithRequest();
        Label30->Caption=PO5->getChangeTime();
        if(PO5->getChangeTime()==0||(PO5->getChangeTime()-PO5->getTimeDelay())<0)
        {
                        och2.addElementInQueue(PO5->sendRequest());
                        Memo2->Lines->Add(och2.showInfo());
        }
       }//закрывает блок пятого ПО
 } //закрывает блок работающих ПО
if(!och2.isEmpty())
 {
  k14.objectNulling(&och2.takeFirstElement());
  numbersOfSuccessRequest++;
  Label37->Caption = numbersOfSuccessRequest;
 }
if(totalNumbersOfRequest!=0)
requestPotential = numbersOfSuccessRequest / totalNumbersOfRequest;
Label38->Caption = FloatToStr(requestPotential);
}//-закрывает общий блок
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void searchGates (TComboBox *comb,TMemo *memo)
{
vector <CGate> vectorGates ;
 vectorGates.push_back(k1);
 vectorGates.push_back(k2);
 vectorGates.push_back(k3);
 vectorGates.push_back(k4);
 vectorGates.push_back(k5);
 vectorGates.push_back(k6);
 vectorGates.push_back(k9);
 vectorGates.push_back(k10);
 vectorGates.push_back(k11);
 vectorGates.push_back(k12);
 vectorGates.push_back(k13);
 vectorGates.push_back(k14);
 vectorGates.push_back(k15);
 vectorGates.push_back(k16);
 vectorGates.push_back(k19);
 vectorGates.push_back(k20);
 vectorGates.push_back(k21);
 vectorGates.push_back(k22);
 vectorGates.push_back(k23);
 vectorGates.push_back(k24);
 vectorGates.push_back(k25);
 vectorGates.push_back(k26);
 vectorGates.push_back(k32);
 for(int i=0; i<32;i++) {
 if(comb->Text == vectorGates[i].CObjectOfControl::getName() )
 memo-> Lines ->Add ( vectorGates[i].CObjectOfControl::connectionInfo());
 }
}
 void searchDevice (TComboBox *comb,TMemo *memo)
{
  vector <CDevice> vectorDevice;
  vectorDevice.push_back(*terminal1);
  vectorDevice.push_back(*terminal2);
  vectorDevice.push_back(*terminal3);
  vectorDevice.push_back(*processor);
  vectorDevice.push_back(*PO1);
  vectorDevice.push_back(*PO2);
  vectorDevice.push_back(*PO3);
  vectorDevice.push_back(*PO4);
  vectorDevice.push_back(*PO5);
 for(int i=0; i<9;i++) {
 if(comb->Text == vectorDevice[i].getName() )
 memo-> Lines ->Add ( vectorDevice[i].connectionInfo());
 }
}
  void searchGenerator (TComboBox *comb,TMemo *memo)
{
  vector <CReqGenerator> vectorGenerator;
  vectorGenerator.push_back(*query1);
  vectorGenerator.push_back(*query2);
  vectorGenerator.push_back(*query3);
  vectorGenerator.push_back(*query4);
  vectorGenerator.push_back(*query5);
 for(int i=0; i<5;i++) {
 if(comb->Text == vectorGenerator[i].getName() )
 memo-> Lines ->Add ( vectorGenerator[i].connectionInfo());
 }
 }
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
searchGates(ComboBox2,Memo4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Lines->Clear();
Memo2->Lines->Clear();
Memo3->Lines->Clear();
Memo4->Lines->Clear();
}
//---------------------------------------------------------------------------
void searchQueue (TComboBox *comb,TMemo *memo)
{
vector <CQueue>  vectorQueueOf ;
 vectorQueueOf.push_back(och1);
 vectorQueueOf.push_back(och2);
 vectorQueueOf.push_back(och3);
 vectorQueueOf.push_back(och4);
 vectorQueueOf.push_back(och5);
 vectorQueueOf.push_back(och6);
 vectorQueueOf.push_back(och7);
 vectorQueueOf.push_back(och8);
 vectorQueueOf.push_back(och9);
 vectorQueueOf.push_back(och10);
 vectorQueueOf.push_back(och11);
 vectorQueueOf.push_back(och12);
 vectorQueueOf.push_back(och13);
 vectorQueueOf.push_back(NMD1);
 vectorQueueOf.push_back(NMD2);
 for(int i=0; i<15;i++) {
 if(comb->Text == vectorQueueOf[i].getName() )
 memo-> Lines ->Add ( vectorQueueOf[i].connectionInfo());
 }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox4Change(TObject *Sender)
{
searchQueue(ComboBox4,Memo4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
searchDevice(ComboBox1,Memo4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
searchGenerator(ComboBox3,Memo4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo3Change(TObject *Sender)
{
Label36->Caption = Memo3->Lines->Count;}
