#include "employe.h"

employe::employe(int d,QString a,QString b,QString c,int e)
{
  nom=b ;
  prenom=c ;
  email=a ;
  id=d ;
  num=e ;
}

bool employe :: ajouter()
{
    QSqlQuery query ;
    QString res= QString::number(id) ;
    QString res2= QString::number(num) ;


    query.prepare("insert into EMPLOYE (ID_EMP,NOM_EMP,PRENOM_EMP,MAIL,TEL)""values(:id,:nom,:prenom,:email,:num)") ;

    query.bindValue(":nom",nom) ;
    query.bindValue(":prenom",prenom) ;
    query.bindValue(":email",email) ;
    query.bindValue(":id",res) ;
    query.bindValue(":num",res2) ;

    return  query.exec() ;
}

bool  employe::supprimer(int id)
{

    QSqlQuery   query;
    QString res=QString::number(id) ;
    query.prepare("delete from EMPLOYE where ID_EMP=:id") ;
    query.bindValue(":id",res) ;

    return  query.exec() ;
}



QSqlQueryModel * employe:: afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel() ;

  model->setQuery("select * from EMPLOYE") ;
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("id")) ;
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom")) ;
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom")) ;
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("email")) ;
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("num")) ;

  return  model ;


}



bool employe::modifier(int id,QString email,QString nom,QString prenom,int num)
 {



     QSqlQuery query ;

     QString res = QString::number(id);
     QString res2 = QString::number(num);




     query.prepare("UPDATE EMPLOYE set ID_EMP=:id,MAIL=:email,NOM_EMP=:nom,PRENOM_EMP=:prenom,TEL=:num where ID_EMP=:id");

     //Création des variables liées
     query.bindValue(":id",res);
     query.bindValue(":email",email);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":num",res2) ;
     return query.exec();

}