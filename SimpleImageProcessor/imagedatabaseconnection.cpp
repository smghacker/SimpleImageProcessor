#include "imagedatabaseconnection.h"
#include <QString>
#include <QByteArray>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
#include<QBuffer>

ImageDatabaseConnection::ImageDatabaseConnection()
{
    QString dbname="postgres";
    this->db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions();
    db.setDatabaseName(dbname);

    if (db.open())
    {
        cout << "Opened\n";
        QString q = "CREATE TABLE Characters ( picture BYTEA, documentName VARCHAR, lineNumber INT, characterNumber INT, xCoordinate INT, yCoordinate INT, PRIMARY KEY (documentName,lineNumber,characterNumber) );";
        db.exec(q);
    }
    else
    {
        cout << "Error = " << db.lastError().text().toStdString();
    }
}

void ImageDatabaseConnection::close()
{
    db.close();
}

void ImageDatabaseConnection::saveImageData(CharacterImage image)
{
    QByteArray picture;
    QBuffer buffer(&picture);
    buffer.open(QIODevice::WriteOnly);
    image.getImage().save(&buffer, "BMP");
    string documentName = image.getDocumentName();
    int lineNumber = image.getLineNumber();
    int characterNumber = image.getCharacterNumber();
    int xCoordinate = image.getXCoordinate();
    int yCoordinate = image.getYCoordinate();
    cout << documentName << " " << lineNumber << " " << characterNumber << endl;
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO Characters (picture, documentName, lineNumber, characterNumber, xCoordinate, yCoordinate) VALUES(:picture, :documentName, :lineNumber, :characterNumber, :xCoordinate, :yCoordinate)");
    query.bindValue(":picture", picture, QSql::In | QSql::Binary);
    query.bindValue(":documentName", documentName.c_str());
    query.bindValue(":lineNumber", lineNumber);
    query.bindValue(":characterNumber", characterNumber);
    query.bindValue(":xCoordinate", xCoordinate);
    query.bindValue(":yCoordinate", yCoordinate);
    query.exec();
}

CharacterImage ImageDatabaseConnection::getImageData(QString documentName, int lineNumber, int characterNumber)
{
    QString q = "SELECT * FROM Characters WHERE documentName='";
    q.append(documentName);
    q.append("' AND lineNumber=");
    q.append(QString::number(lineNumber));
    q.append(" AND characterNumber=");
    q.append(QString::number(characterNumber));
    q.append(";");
    cout << q.toStdString() << endl;
    int xCoordinate;
    int yCoordinate;
    QSqlQuery query =  db.exec(q);
    query.first();
    QImage image = QImage::fromData(query.value(0).toByteArray(), "BMP");
    xCoordinate = query.value(4).toInt();
    yCoordinate = query.value(5).toInt();

    CharacterImage res(image, documentName.toStdString(), lineNumber, characterNumber, xCoordinate, yCoordinate);
    return res;
}
