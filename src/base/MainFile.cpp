/************************************************************
 *
 *  MainFile.cpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
**************************************************************/

#include "MainFile.hpp"
#include "OTServer.hpp"
#include "Helpers.hpp"
#include <opentxs/core/OTString.hpp>
#include <opentxs/core/crypto/OTCachedKey.hpp>
#include <opentxs/core/crypto/OTASCIIArmor.hpp>
#include <opentxs/core/OTLog.hpp>
#include <opentxs/core/OTIdentifier.hpp>
#include <opentxs/core/OTContract.hpp>
#include <opentxs/core/OTServerContract.hpp>
#include <opentxs/core/OTAssetContract.hpp>
#include <opentxs/core/crypto/OTPassword.hpp>
#include <opentxs/core/OTStorage.hpp>
#include <opentxs/core/OTFolders.hpp>
#include <irrxml/irrXML.hpp>
#include <string>
#include <memory>

namespace opentxs
{

MainFile::MainFile(OTServer* server)
    : m_strVersion()
    , server_(server)
{
}

bool MainFile::SaveMainFileToString(OTString& strMainFile)
{
    const char* szFunc = "MainFile::SaveMainFileToString";

    strMainFile.Format(
        "<?xml version=\"1.0\"?>\n"
        "<notaryServer version=\"%s\"\n"
        " serverID=\"%s\"\n"
        " serverUserID=\"%s\"\n"
        " transactionNum=\"%ld\" >\n\n",
        OTCachedKey::It()->IsGenerated() ? "2.0" : m_strVersion.Get(),
        server_->m_strServerID.Get(), server_->m_strServerUserID.Get(),
        server_->transactor_.transactionNumber());

    if (OTCachedKey::It()->IsGenerated()) // If it exists, then serialize it.
    {
        OTASCIIArmor ascMasterContents;

        if (OTCachedKey::It()->SerializeTo(ascMasterContents)) {
            strMainFile.Concatenate("<cachedKey>\n%s</cachedKey>\n\n",
                                    ascMasterContents.Get());
        }
        else
            OTLog::vError(
                "%s: Failed trying to write master key to notary file.\n",
                szFunc);
    }

    // ContractsMap    contractsMap_;   // If the server needs to store
    // copies of the asset contracts, then here they are.
    // MintsMap        m_mapMints;          // Mints for each of those.

    for (auto& it : server_->transactor_.contractsMap_) {
        OTContract* pContract = it.second;
        OT_ASSERT_MSG(nullptr != pContract,
                      "nullptr contract pointer in MainFile::SaveMainFile.\n");

        // This is like the Server's wallet.
        pContract->SaveContractWallet(strMainFile);
    }

    // Save the basket account information

    for (auto& it : server_->transactor_.idToBasketMap_) {
        OTString strBasketID = it.first.c_str();
        OTString strBasketAcctID = it.second.c_str();

        const OTIdentifier BASKET_ACCOUNT_ID(strBasketAcctID);
        OTIdentifier BASKET_CONTRACT_ID;

        bool bContractID =
            server_->transactor_.lookupBasketContractIDByAccountID(
                BASKET_ACCOUNT_ID, BASKET_CONTRACT_ID);

        if (!bContractID) {
            OTLog::vError("%s: Error: Missing Contract ID for basket ID %s\n",
                          szFunc, strBasketID.Get());
            break;
        }

        OTString strBasketContractID(BASKET_CONTRACT_ID);

        strMainFile.Concatenate("<basketInfo basketID=\"%s\"\n"
                                " basketAcctID=\"%s\"\n"
                                " basketContractID=\"%s\" />\n\n",
                                strBasketID.Get(), strBasketAcctID.Get(),
                                strBasketContractID.Get());
    }

    server_->transactor_.voucherAccounts_.Serialize(strMainFile);

    strMainFile.Concatenate("</notaryServer>\n");

    return true;
}

// Setup the default location for the Sever Main File...
// maybe this should be set differently...
// should be set in the servers configuration.
//
bool MainFile::SaveMainFile()
{
    // Get the loaded (or new) version of the Server's Main File.
    //
    OTString strMainFile;

    if (false == SaveMainFileToString(strMainFile)) {
        OTLog::vError(
            "%s: Error saving to string. (Giving up on save attempt.)\n",
            __FUNCTION__);
        return false;
    }
    // Try to save the notary server's main datafile to local storage...
    //
    OTString strFinal;
    OTASCIIArmor ascTemp(strMainFile);

    if (false ==
        ascTemp.WriteArmoredString(strFinal, "NOTARY")) // todo hardcoding.
    {

        OTLog::vError(
            "%s: Error saving notary (failed writing armored string)\n",
            __FUNCTION__);
        return false;
    }
    // Save the Main File to the Harddrive... (or DB, if other storage module is
    // being used).
    //
    const bool bSaved = OTDB::StorePlainString(
        strFinal.Get(), ".", server_->m_strWalletFilename.Get());

    if (!bSaved) // Check if successfull.
        OTLog::vError("%s: Error saving main file: %s\n", __FUNCTION__,
                      server_->m_strWalletFilename.Get());

    return bSaved;
}

bool MainFile::CreateMainFile()
{
    const char* szInstructions =
        "\n\n ==> WARNING: Main file not found. To create it, continue this "
        "process now...\n\n"
        "REQUIREMENTS: You must already have a wallet, where you have created "
        "one Nym.\n"
        "This will be a temporary wallet only, for the purpose of generating "
        "the server\n"
        "nym and the master key for that server nym. You can erase the "
        "contents of the\n"
        "~/.ot/client_data folder once we are done with this process, and the "
        "OT client\n"
        "will just create a fresh wallet to replace it. In other words, don't "
        "continue\n"
        "to use the temporary wallet as a REAL wallet, since it contains the "
        "master\n"
        "key and private key for your new server nym. We're using a temporary "
        "client-side\n"
        "wallet for the convenience of generating the server nym--we'll copy "
        "it over to \n"
        "the server side, and then we'll wipe the temp wallet and start with a "
        "fresh one\n"
        "once this process is done.\n"
        "(FYI, you can decode an armored wallet by using the 'opentxs decode' "
        "command.)\n"
        "-- You must also have the new Server Nym's \"NymID\", which should be "
        "found in the\nwallet.\n"
        "-- When you have created your server Nym (using your temp wallet) you "
        "will want to\n"
        "copy the credentials from the temp wallet to your new server:\n"
        "    cp -R ~/.ot/client_data/credentials ~/.ot/server_data/ \n"
        "-- You must already have a signed server contract. (*** To get one, "
        "copy the\n"
        "UNSIGNED version of the sample server contract, which is named "
        "'localhost.xml',\n"
        "and then change the tags as you see fit. Then use the same Nym, the "
        "server Nym,\n"
        "to sign the server contract, via the 'opentxs newserver' "
        "command.***)\n"
        "You must also have the server ID for the above contract, which the "
        "newserver\n"
        "command will output at the same time it outputs the newly-signed "
        "server contract.\n"
        "=> Note that the Nym who signs the server contract MUST be the same "
        "Nym that you\n"
        "provide HERE, for this process now...)\n"
        "-- Finally, you must provide the cached key from the same wallet "
        "where you brought\n"
        "the Nym from (In this case, be careful to only copy the "
        "base64-encoded portion\n"
        "of the cached key from the wallet, and not the XML tags around it!) "
        "We\n"
        "recommend you create a blank wallet entirely for this purpose (of "
        "generating\n"
        "that cached key and server Nym, to be used for your new OT server.) "
        "Then erase it\nonce this process is done.\n"
        " ==> WARNING: Main file not found. To create it, continue this "
        "process now...\n";

    OTLog::Output(0, szInstructions);
    OTLog::Output(0, "Enter the ServerID for your server contract: ");
    std::string strServerID = OT_CLI_ReadLine();
    OTLog::Output(0, "Enter the Server User ID (the NymID of the Nym who "
                     "signed the server contract): ");
    std::string strNymID = OT_CLI_ReadLine();
    OTLog::Output(0, "Paste the cached key (ONLY the base64-encoded portion) "
                     "below, from wallet.xml for that Nym.\n"
                     "Terminate with '~' on a line by itself.\n\n");

    std::string strCachedKey = OT_CLI_ReadUntilEOF();
    OTLog::Output(0, "Paste the contents of the server Nym's certfile, "
                     "including public/PRIVATE, below.\n"
                     "NOTE: LEAVE THIS BLANK unless you REALLY want to use the "
                     "OLD system. If you leave this\n"
                     "blank (preferred), it will instead use the new "
                     "credentials system. (Just make sure\n"
                     "you copied over the \"credentials\" folder, as described "
                     "above, since we're about to\n"
                     "use it, if you leave this blank.)\n"
                     "Terminate with '~' on a line by itself.\n\n");

    std::string strCert = OT_CLI_ReadUntilEOF();
    // signed server contract
    OTLog::Output(0, "Paste the complete, signed, server contract below. (You "
                     "must already have it.)\n"
                     "Terminate with '~' on a line by itself.\n\n");

    std::string strContract = OT_CLI_ReadUntilEOF();
    if (!OTDB::StorePlainString(strContract, "contracts", strServerID)) {
        OTLog::Error("Failed trying to store the server contract.\n");
        return false;
    }
    if ((strCert.size()) > 0 &&
        !OTDB::StorePlainString(strCert, "certs", strNymID)) {
        OTLog::Error(
            "Failed trying to store the server Nym's public/private cert.\n");
        return false;
    }
    const char* szBlankFile = // todo hardcoding.
        "<?xml version=\"1.0\"?>\n"
        "<notaryServer version=\"2.0\"\n"
        " serverID=\"%s\"\n"
        " serverUserID=\"%s\"\n"
        " transactionNum=\"%ld\" >\n"
        "\n"
        "<cachedKey>\n"
        "%s</cachedKey>\n"
        "\n"
        "<accountList type=\"voucher\" count=\"0\" >\n"
        "\n"
        "</accountList>\n"
        "\n"
        "</notaryServer>\n\n";

    const int64_t lTransNum = 5; // a starting point, for the new server.

    OTString strNotaryFile;
    strNotaryFile.Format(szBlankFile, strServerID.c_str(), strNymID.c_str(),
                         lTransNum, strCachedKey.c_str());

    std::string str_Notary(strNotaryFile.Get());

    if (!OTDB::StorePlainString(str_Notary, ".",
                                "notaryServer.xml")) // todo hardcoding.
    {
        OTLog::Error("Failed trying to store the new notaryServer.xml file.\n");
        return false;
    }
    OTASCIIArmor ascCachedKey;
    ascCachedKey.Set(strCachedKey.c_str());
    OTCachedKey::It()->SetCachedKey(ascCachedKey);

    if (!OTCachedKey::It()->HasHashCheck()) {
        OTPassword tempPassword;
        tempPassword.zeroMemory();
        std::shared_ptr<OTCachedKey> sharedPtr(OTCachedKey::It());
        sharedPtr->GetMasterPassword(
            sharedPtr, tempPassword,
            "We do not have a check hash yet for this password, "
            "please enter your password",
            true);
        if (!SaveMainFile()) {
            OT_FAIL;
        }
    }
    // At this point, the contract is saved, the cert is saved, and the
    // notaryServer.xml file
    // is saved. All we have left is the Nymfile, which we'll create.

    const OTString strServerUserID(strNymID.c_str());

    server_->m_nymServer.SetIdentifier(strServerUserID);

    if (!server_->m_nymServer.Loadx509CertAndPrivateKey()) {
        OTLog::vOutput(0, "%s: Error loading server credentials, or "
                          "certificate and private key.\n",
                       __FUNCTION__);
    }
    else if (!server_->m_nymServer.VerifyPseudonym()) {
        OTLog::vOutput(0, "%s: Error verifying server nym. Are you sure you "
                          "have the right ID?\n",
                       __FUNCTION__);
    }
    else if (!server_->m_nymServer.SaveSignedNymfile(server_->m_nymServer)) {
        OTLog::vOutput(0, "%s: Error saving new nymfile for server nym.\n",
                       __FUNCTION__);
    }
    else {
        OTLog::vOutput(0, "%s: OKAY, we have apparently created the new "
                          "server. Remember to erase the contents "
                          "of your ~/.ot/client_data folder, since we used a "
                          "temporary wallet to generate the server "
                          "nym and its master key.\n"
                          "Let's try to load up your new server contract...\n",
                       __FUNCTION__);
        return true;
    }

    return false;
}

bool MainFile::LoadMainFile(bool bReadOnly)
{
    //
    if (!OTDB::Exists(".", server_->m_strWalletFilename.Get())) {
        OTLog::vError("%s: Error finding file: %s\n", __FUNCTION__,
                      server_->m_strWalletFilename.Get());
        return false;
    }
    OTString strFileContents(OTDB::QueryPlainString(
        ".",
        server_->m_strWalletFilename.Get())); // <=== LOADING FROM DATA STORE.

    if (!strFileContents.Exists()) {
        OTLog::vError("%s: Unable to read main file: %s\n", __FUNCTION__,
                      server_->m_strWalletFilename.Get());
        return false;
    }
    //
    // If, for example, the server user Nym is in old format (no master key)
    // then we will set this to true while loading. Then at the BOTTOM of this
    // function, we'll convert the Nym to the new format and re-save the notary
    // file.
    //
    bool bNeedToConvertUser = false;
    bool bNeedToSaveAgain = false;

    bool bFailure = false;

    {
        OTStringXML xmlFileContents(strFileContents);

        if (false ==
            xmlFileContents.DecodeIfArmored()) // bEscapedIsAllowed=true by
                                               // default.
        {
            OTLog::vError("%s: Notary server file apparently was encoded and "
                          "then failed decoding. Filename: %s \n"
                          "Contents: \n%s\n",
                          __FUNCTION__, server_->m_strWalletFilename.Get(),
                          strFileContents.Get());
            return false;
        }
        irr::io::IrrXMLReader* xml =
            irr::io::createIrrXMLReader(xmlFileContents);
        // cppcheck-suppress unreadVariable
        std::unique_ptr<irr::io::IrrXMLReader> theXMLGuardian(xml);
        while (xml && xml->read()) {
            // strings for storing the data that we want to read out of the file

            OTString AssetName;
            OTString AssetContract;
            OTString AssetID;

            const OTString strNodeName(xml->getNodeName());

            switch (xml->getNodeType()) {
            case irr::io::EXN_TEXT:
                // in this xml file, the only text which occurs is the
                // messageText
                // messageText = xml->getNodeData();
                break;
            case irr::io::EXN_ELEMENT: {
                if (strNodeName.Compare("notaryServer")) {
                    m_strVersion = xml->getAttributeValue("version");
                    server_->m_strServerID = xml->getAttributeValue("serverID");
                    server_->m_strServerUserID =
                        xml->getAttributeValue("serverUserID");

                    OTString strTransactionNumber; // The server issues
                                                   // transaction numbers and
                                                   // stores the counter here
                                                   // for the latest one.
                    strTransactionNumber =
                        xml->getAttributeValue("transactionNum");
                    server_->transactor_.transactionNumber(
                        atol(strTransactionNumber.Get()));

                    OTLog::vOutput(
                        0,
                        "\nLoading Open Transactions server. File version: %s\n"
                        " Last Issued Transaction Number: %ld\n Server ID:     "
                        " %s\n Server User ID: %s\n",
                        m_strVersion.Get(),
                        server_->transactor_.transactionNumber(),
                        server_->m_strServerID.Get(),
                        server_->m_strServerUserID.Get());
                    //
                    if (m_strVersion.Compare("1.0")) // This means this
                                                     // Nym has
                                                     // not been converted yet
                                                     // to master password.
                    {
                        bNeedToConvertUser = true;

                        if (!(OTCachedKey::It()->isPaused()))
                            OTCachedKey::It()->Pause();

                        if (!LoadServerUserAndContract()) {
                            OTLog::vError("%s: Failed calling "
                                          "LoadServerUserAndContract.\n",
                                          __FUNCTION__);
                            bFailure = true;
                        }

                        if (OTCachedKey::It()->isPaused())
                            OTCachedKey::It()->Unpause();
                    }
                }
                // todo in the future just remove masterkey. I'm leaving it for
                // now so people's
                // data files can get converted over. After a while just remove
                // it.
                //
                else if (strNodeName.Compare("masterKey") ||
                         strNodeName.Compare("cachedKey")) {
                    OTASCIIArmor ascCachedKey;

                    if (OTContract::LoadEncodedTextField(xml, ascCachedKey)) {
                        // We successfully loaded the masterKey from file, so
                        // let's SET it
                        // as the master key globally...
                        //
                        OTCachedKey::It()->SetCachedKey(ascCachedKey);

                        if (!OTCachedKey::It()->HasHashCheck()) {
                            OTPassword tempPassword;
                            tempPassword.zeroMemory();
                            std::shared_ptr<OTCachedKey> sharedPtr(
                                OTCachedKey::It());
                            bNeedToSaveAgain = sharedPtr->GetMasterPassword(
                                sharedPtr, tempPassword,
                                "We do not have a check hash yet for this "
                                "password, "
                                "please enter your password",
                                true);
                        }
                    }

                    OTLog::vOutput(0, "\nLoading cachedKey:\n%s\n",
                                   ascCachedKey.Get());
                    //
                    // It's only here, AFTER the master key has been loaded,
                    // that we can
                    // go ahead and load the server user, the server contract,
                    // cron, etc.
                    // (It wasn't that way in version 1, before we had master
                    // keys.)
                    //
                    if (false == m_strVersion.Compare("1.0")) // This is, for
                                                              // example, 2.0
                    {
                        if (!LoadServerUserAndContract()) {
                            OTLog::vError("%s: Failed calling "
                                          "LoadServerUserAndContract.\n",
                                          __FUNCTION__);
                            bFailure = true;
                        }
                    }
                }
                else if (strNodeName.Compare("accountList")) // the voucher
                                                               // reserve
                                                               // account IDs.
                {
                    const OTString strAcctType = xml->getAttributeValue("type");
                    const OTString strAcctCount =
                        xml->getAttributeValue("count");

                    if ((-1) ==
                        server_->transactor_.voucherAccounts_.ReadFromXMLNode(
                            xml, strAcctType, strAcctCount))
                        OTLog::vError(
                            "%s: Error loading voucher accountList.\n",
                            __FUNCTION__);
                }
                else if (strNodeName.Compare("basketInfo")) {
                    OTString strBasketID = xml->getAttributeValue("basketID");
                    OTString strBasketAcctID =
                        xml->getAttributeValue("basketAcctID");
                    OTString strBasketContractID =
                        xml->getAttributeValue("basketContractID");

                    const OTIdentifier BASKET_ID(strBasketID),
                        BASKET_ACCT_ID(strBasketAcctID),
                        BASKET_CONTRACT_ID(strBasketContractID);

                    if (server_->transactor_.addBasketAccountID(
                            BASKET_ID, BASKET_ACCT_ID, BASKET_CONTRACT_ID))
                        OTLog::vOutput(0, "Loading basket currency info...\n "
                                          "Basket ID: %s\n Basket Acct ID: "
                                          "%s\n Basket Contract ID: %s\n",
                                       strBasketID.Get(), strBasketAcctID.Get(),
                                       strBasketContractID.Get());
                    else
                        OTLog::vError("Error adding basket currency info...\n "
                                      "Basket ID: %s\n Basket Acct ID: %s\n",
                                      strBasketID.Get(), strBasketAcctID.Get());
                }

                // Create an OTAssetContract and load them from file, (for each
                // asset type),
                // and add them to the internal map.
                else if (strNodeName.Compare("assetType")) {
                    OTASCIIArmor ascAssetName = xml->getAttributeValue("name");

                    if (ascAssetName.Exists())
                        ascAssetName.GetString(AssetName,
                                               false); // linebreaks == false

                    AssetID = xml->getAttributeValue(
                        "assetTypeID"); // hash of contract itself

                    OTLog::vOutput(0, "\n\n****Asset Contract**** (server "
                                      "listing)\n Name: %s\n Contract ID: %s\n",
                                   AssetName.Get(), AssetID.Get());

                    OTString strContractPath;
                    strContractPath = OTFolders::Contract().Get();

                    OTAssetContract* pContract = new OTAssetContract(
                        AssetName, strContractPath, AssetID, AssetID);

                    OT_ASSERT_MSG(nullptr != pContract,
                                  "ASSERT: allocating memory for Asset "
                                  "Contract in MainFile::LoadMainFile\n");

                    if (pContract->LoadContract()) {
                        if (pContract->VerifyContract()) {
                            OTLog::Output(0, "** Asset Contract Verified **\n");

                            pContract->SetName(AssetName);

                            server_->transactor_.contractsMap_[AssetID.Get()] =
                                pContract;
                        }
                        else {
                            delete pContract;
                            pContract = nullptr;
                            OTLog::Output(0,
                                          "Asset Contract FAILED to verify.\n");
                        }
                    }
                    else {
                        delete pContract;
                        pContract = nullptr;
                        OTLog::vOutput(
                            0, "%s: Failed reading file for Asset Contract.\n",
                            __FUNCTION__);
                    }
                }

                // This is where the server finds out his own contract, which he
                // hashes in order to verify his
                // serverID (which is either hardcoded or stored in the server
                // xml file.)
                //
                // There should be only one of these per transaction server.
                //
                // Commented out because I don't need it right now. TODO. COMING
                // SOON! So the server can load his
                // port information out of the contract BEFORE it starts
                // listening on the port (right now port is
                // still hardcoded.)
                // Todo: Server should also then immediately connect to itself
                // BASED ON THE INFO IN THE CONTRACT
                // in order to verify that whatever is running at that port IS,
                // IN FACT, ITSELF!
                /*
                  else if (strNodeName.Compare("notaryProvider"))
                  {
                  ServerName        = xml->getAttributeValue("name");
                  ServerID        = xml->getAttributeValue("serverID");    //
                  hash of contract itself

                  OTLog::vOutput(0, "\n\n****Notary Server (contract)****
                  (server listing) Name: %s\nContract ID:\n%s\n",
                  ServerName.Get(), ServerID.Get());

                  OTString strContractPath;
                  strContractPath.Format("%s%s%s%s%s", OTLog::Path(),
                  OTLog::PathSeparator(),
                  OTFolders::Contract().Get(),
                  OTLog::PathSeparator(), ServerID.Get());
                  MainFileContract * pContract = new
                  MainFileContract(ServerName, strContractPath, ServerID);

                  OT_ASSERT_MSG(nullptr != pContract, "Error allocating memory
                  for
                  Server Contract in MainFile::LoadMainFile\n");

                  if (pContract->LoadContract())
                  {
                  if (pContract->VerifyContract())
                  {
                  OTLog::Output(0, "** Server Contract Verified **\n");

                  contractsMap_[ServerID.Get()] = pContract;
                  }
                  else
                  {
                  delete pContract; pContract = nullptr;
                  OTLog::Output(0, "Server Contract FAILED to verify.\n");
                  }
                  }
                  else
                  {
                  delete pContract; pContract = nullptr;
                  OTLog::Output(0, "Failed reading file for Server Contract in
                  MainFile::LoadMainFile\n");
                  }
                  }
                */

                /*
                // commented out because, since I already have the serverID,
                then the server
                // already knows which certfile to open in order to get at its
                private key.
                // So I already have the private key loaded, so I don't need
                pseudonyms in
                // the config file right now.
                //
                // In the future, I will load the server XML file (here) FIRST,
                and get the serverID and
                // contract file from that. THEN I will hash the contract file
                and verify that it matches
                // the serverID. THEN I will use that serverID to open the
                Certfile and get my private key.
                //
                // In the meantime I don't need this yet, serverID is setup in
                the config file (that I'm reading now.)
                else if (strNodeName.Compare("pseudonym")) // The server has to
                sign things, too.
                {
                NymName = xml->getAttributeValue("name");// user-assigned name
                for GUI usage
                NymID = xml->getAttributeValue("nymID"); // message digest from
                hash of x.509 cert, used to look up certfile.

                OTLog::vOutput(0, "\n\n** Pseudonym ** (server): %s\nID:
                %s\nfile: %s\n",
                NymName.Get(), NymID.Get(), NymFile.Get());

                OTPseudonym * pNym = new OTPseudonym(NymName, NymFile, NymID);

                if (pNym && pNym->LoadNymfile((char*)(NymFile.Get())))
                {
                if (pNym->Loadx509CertAndPrivateKey())
                {
                if (pNym->VerifyPseudonym())
                {
                m_mapNyms[NymID.Get()] = pNym;
                g_pTemporaryNym = pNym; // TODO remove this temporary line used
                for testing only.
                }
                else {
                OTLog::Error("Error verifying public key from x509 against Nym
                ID in OTWallet::LoadWallet\n");
                }
                }
                else {
                OTLog::Error("Error loading x509 file for Pseudonym in
                OTWallet::LoadWallet\n");
                }
                }
                else {
                OTLog::Error("Error creating or loading Nym in
                OTWallet::LoadWallet\n");
                }
                }
                */
                else {
                    // unknown element type
                    OTLog::vError("%s: Unknown element type: %s\n",
                                  __FUNCTION__, xml->getNodeName());
                }
            } break;
            default:
                break;
            } // switch
        }     // while xml->read
    }
    if (!bReadOnly) {
        {
            OTString strReason("Converting Server Nym to master key.");
            if (bNeedToConvertUser &&
                server_->m_nymServer.Savex509CertAndPrivateKey(true,
                                                               &strReason))
                SaveMainFile();
        }
        {
            OTString strReason("Creating a Hash Check for the master key.");
            if (bNeedToSaveAgain &&
                server_->m_nymServer.Savex509CertAndPrivateKey(true,
                                                               &strReason))
                SaveMainFile();
        }
    }
    return !bFailure;
}

bool MainFile::LoadServerUserAndContract()
{
    const char* szFunc = "MainFile::LoadServerUserAndContract";
    bool bSuccess = false;
    OT_ASSERT(m_strVersion.Exists());
    OT_ASSERT(server_->m_strServerID.Exists());
    OT_ASSERT(server_->m_strServerUserID.Exists());
    //
    server_->m_nymServer.SetIdentifier(server_->m_strServerUserID);

    if (!server_->m_nymServer.Loadx509CertAndPrivateKey(false)) {
        OTLog::vOutput(0, "%s: Error loading server certificate and keys.\n",
                       szFunc);
    }
    else if (!server_->m_nymServer.VerifyPseudonym()) {
        OTLog::vOutput(0, "%s: Error verifying server nym.\n", szFunc);
    }
    else {
        // This file will be saved during the course of operation
        // Just making sure it is loaded up first.
        //
        bool bLoadedSignedNymfile =
            server_->m_nymServer.LoadSignedNymfile(server_->m_nymServer);
        OT_ASSERT_MSG(bLoadedSignedNymfile,
                      "ASSERT: MainFile::LoadServerUserAndContract: "
                      "m_nymServer.LoadSignedNymfile(m_nymServer)\n");
        //      m_nymServer.SaveSignedNymfile(m_nymServer); // Uncomment this if
        // you want to create the file. NORMALLY LEAVE IT OUT!!!! DANGEROUS!!!

        OTLog::vOutput(
            0,
            "%s: Loaded server certificate and keys.\nNext, loading Cron...\n",
            szFunc);
        // Load Cron (now that we have the server Nym.
        // (I WAS loading this erroneously in Server.Init(), before
        // the Nym had actually been loaded from disk. That didn't work.)
        //
        const OTIdentifier SERVER_ID(server_->m_strServerID);

        // Make sure the Cron object has a pointer to the server's Nym.
        // (For signing stuff...)
        //
        server_->m_Cron.SetServerID(SERVER_ID);
        server_->m_Cron.SetServerNym(&server_->m_nymServer);

        if (!server_->m_Cron.LoadCron())
            OTLog::vError("%s: Failed loading Cron file. (Did you just create "
                          "this server?)\n",
                          szFunc);
        OTLog::vOutput(0, "%s: Loading the server contract...\n", szFunc);

        // We have the serverID, so let's load  up the server Contract!
        OTString strContractPath(OTFolders::Contract().Get());

        std::unique_ptr<OTServerContract> pContract(new OTServerContract(
            server_->m_strServerID, strContractPath, server_->m_strServerID,
            server_->m_strServerID));
        OT_ASSERT_MSG(nullptr != pContract,
                      "ASSERT while allocating memory for main Server Contract "
                      "in MainFile::LoadServerUserAndContract\n");

        if (pContract->LoadContract()) {
            if (pContract->VerifyContract()) {
                OTLog::Output(0, "\n** Main Server Contract Verified **\n");
                server_->m_pServerContract.swap(pContract);
                bSuccess = true;
            }
            else {
                OTLog::Output(0, "\nMain Server Contract FAILED to verify.\n");
            }
        }
        else {
            OTLog::vOutput(0,
                           "\n%s: Failed reading Main Server Contract:\n%s\n",
                           szFunc, strContractPath.Get());
        }
    }

    return bSuccess;
}

} // namespace opentxs
