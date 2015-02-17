/*M///////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014, sheng
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimer in the documentation
//       and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//M*/



/**
 * @brief
 * @return
 * @author sheng
 * @date
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng                 0.1
 *
 */

#include <iostream>

#include <QPushButton>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lineeditcreator.h"

#include "pricelineedit.h"
#include "numberlineedit.h"


/**
 * @brief MainWindow::MainWindow Constructor
 * @param parent The parent widght
 *
 * @author sheng
 * @date 2015-02-15
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng        2015-02-15         0.1       build thee function
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}




/**
 * @brief MainWindow::~MainWindow The deconstructor
 *
 * @author sheng
 * @date 2015-02-15
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng        2015-02-15         0.1       build thee function
 *
 */
MainWindow::~MainWindow()
{
    delete ui;
}




/**
 * @brief MainWindow::CreateRows  Create empty rows
 * @param NumberOfRows The number of the rows
 *
 * @author sheng
 * @date 2015-02-15
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng        2015-02-15         0.1       build thee function
 *
 */
void MainWindow::CreateRows(const int NumberOfRows)
{
    for (int Index = 0; Index < NumberOfRows; Index++)
    {
        //
        int RowNumber = ui->tableWidget->rowCount() - 1;

        // insert a empty row
        ui->tableWidget->insertRow(RowNumber);


        // add the numberlineedit to the row
        NumberLineEdit* Numberlineedit  = new NumberLineEdit(RowNumber);
        Numberlineedit->setFocusPolicy(Qt::ClickFocus);
        ui->tableWidget->setCellWidget(RowNumber, NUMBER, Numberlineedit);
        connect(Numberlineedit, SIGNAL(FinishingLineedit(int)),
                this, SLOT(UpdateSum(int)));


        // add the pricelineedit to the row
        PriceLineEdit* Pricelineedit = new PriceLineEdit(RowNumber);
        ui->tableWidget->setCellWidget(RowNumber, PRICE, Pricelineedit);
        connect(Pricelineedit, SIGNAL(FinishingLineedit(int)),
                this, SLOT(UpdateSum(int)));


        // set the initial value of the sum
        QTableWidgetItem* Item = new QTableWidgetItem(QString::number(0.0f));
        Item->setFlags(Qt::NoItemFlags);
        Item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(RowNumber, SUM, Item);
    }
}




/**
 * @brief MainWindow::UpdateSum The slot to update the sum of the No.RowNumber
 *                              row and the final sum.
 * @param RowNumber The index of the row
 *
 * @author sheng
 * @date 2015-02-15
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng        2015-02-15         0.1       build thee function
 *
 */
void MainWindow::UpdateSum(int RowNumber)
{
    // get the old value of the sum
    QTableWidgetItem* Item = ui->tableWidget->item(RowNumber, SUM);
    float RowSumOld = Item->text().toFloat();

    // return if the item is null
    if (!Item)
    {
        std::cout << "The item is null" << std::endl;
        return;
    }


    // get the NumberLineEdit and the number
    NumberLineEdit* Numberlineedit = (NumberLineEdit *)(ui->tableWidget->cellWidget(RowNumber, NUMBER));
    int Number = Numberlineedit->text().toInt();


    // get the PriceLineEdit and the price
    PriceLineEdit* Pricelineedit = (PriceLineEdit*)(ui->tableWidget->cellWidget(RowNumber, PRICE));
    float Price = Pricelineedit->text().toFloat();


    // calculate the new row sum
    float RowSumNew = Number * Price;
    Item->setText(QString::number(RowSumNew));


    // update the sum
    int RowCount = ui->tableWidget->rowCount();
    float SumOld = ui->tableWidget->item(RowCount - 1, SUM)->text().toFloat();
    float SumNew = SumOld - RowSumOld + RowSumNew;
    ui->tableWidget->item(RowCount - 1, SUM)->setText(QString::number(SumNew));

}

