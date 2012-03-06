/****************************************************************************
** Copyright (C) 2010-2012 Klaralvdalens Datakonsult AB.  All rights reserved.
**
** This file is part of the KD Soap library.
**
** Licensees holding valid commercial KD Soap licenses may use this file in
** accordance with the KD Soap Commercial License Agreement provided with
** the Software.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 and version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE.GPL.txt included.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
**********************************************************************/
#ifndef KDSOAPSERVERAUTHINTERFACE_H
#define KDSOAPSERVERAUTHINTERFACE_H

#include "KDSoapServerGlobal.h"
#include <QtCore/QObject>
class KDSoapAuthentication;
class KDSoapServerSocket;

/**
 * Additional interface for handling authentication.
 *
 * In addition to deriving from KDSoapServerObjectInterface, you can derive from
 * KDSoapServerAuthInterface in order to handle HTTP authentication.
 *
 * \since 1.3
 */
class KDSOAPSERVER_EXPORT KDSoapServerAuthInterface
{
public:
    /**
     * Constructor
     */
    KDSoapServerAuthInterface();

    /**
     * Destructor
     */
    virtual ~KDSoapServerAuthInterface();

    /**
     * Return true if the authentication details are valid.
     */
    virtual bool validateAuthentication(const KDSoapAuthentication& auth, const QString &path);

private:
    friend class KDSoapServerSocket;
    bool handleHttpAuth(const QByteArray &authValue, const QString &path);
    class Private;
    Private* const d;
};

Q_DECLARE_INTERFACE(KDSoapServerAuthInterface,
                    "com.kdab.KDSoap.ServerAuthInterface/1.0")


#endif /* KDSOAPSERVERAUTHINTERFACE_H */
