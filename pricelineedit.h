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

#ifndef PRICELINEEDIT_H
#define PRICELINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QWidget>


class PriceLineEdit : public QLineEdit
{

    Q_OBJECT

    public:
        PriceLineEdit(int RowNumber, double Bottom = 0.0 , double Top = 9999.9,
                      int Decimals = 1, QWidget *Parent = 0);
        ~PriceLineEdit();

    private:
        int Row;

    private slots:
        void FinishingEdit();

    signals:
        void FinishingLineedit(int RowNumber);




};

#endif // PRICELINEEDIT_H
