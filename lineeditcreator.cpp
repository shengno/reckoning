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



#include "lineeditcreator.h"


/**
 * @brief CreateFloatLineEdit The function to create a LineEdit which deal with
 *                            float-point number only.
 * @param Bottom    The low bound of the input value.
 * @param Top       The high bound of the input value.
 * @param Decimals  The number of the decimal of the input value.
 * @return The LineEdit which deal with float-point number only.
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
QLineEdit* CreateFloatLineEdit(double Bottom, double Top, int Decimals)
{
    QLineEdit* PriceLineedit = new QLineEdit;


    // set double validator
    QDoubleValidator* PriceValidator = new QDoubleValidator(Bottom, Top, Decimals,
                                                            PriceLineedit);

    // set the notation to be the normal notation
    PriceValidator->setNotation(QDoubleValidator::StandardNotation);


    PriceLineedit->setValidator(PriceValidator);

    return PriceLineedit;
}




/**
 * @brief CreateIntegerLineEdit The function to create a LineEdit which deal with
 *                             the integer only
 * @param Min  The low bound of the input value.
 * @param Max  The high bound of the input value.
 * @return The LineEdit which deal with integer only.
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
QLineEdit* CreateIntegerLineEdit(int Min, int Max)
{

    QLineEdit* NumberLineEdit = new QLineEdit;


    // number validator
    QIntValidator* NumberValidator = new QIntValidator(Min, Max, NumberLineEdit);

    NumberLineEdit->setValidator(NumberValidator);


    // initial value
    NumberLineEdit->setText(QString("0"));

    return NumberLineEdit;
}

