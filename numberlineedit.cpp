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




#include "numberlineedit.h"


/**
 * @brief NumberLineEdit::NumberLineEdit The constructor of class NumberLineEdit.
 * @param RowNumber The row index of the tablewidgt
 * @param Min       The minimal value for the number
 * @param Max       The max value for the number
 * @param Parent    The parent wight
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
NumberLineEdit::NumberLineEdit(int RowNumber, int Min, int Max, QWidget *Parent)
    : QLineEdit(Parent), Row(RowNumber)
{
    // set number validator
    QIntValidator* NumberValidator = new QIntValidator(Min, Max, this);


    this->setValidator(NumberValidator);


    // set initial value
    this->setText(QString::number(0));


    // connect the editingfinished signal
    connect(this, SIGNAL(editingFinished()), this, SLOT(FinishingEdit()));
}




/**
 * @brief NumberLineEdit::~NumberLineEdit The deconstructor
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
NumberLineEdit::~NumberLineEdit()
{

}




/**
 * @brief NumberLineEdit::FinishingEdit  The slot to emit the FinishingLineedit
 *                                       signal.
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
void NumberLineEdit::FinishingEdit()
{
    emit FinishingLineedit(Row);
}






