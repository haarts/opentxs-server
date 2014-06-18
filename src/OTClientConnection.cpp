/************************************************************************************
 *
 *  OTCLientConnection.cpp
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

#include <stdafx.hpp>

#include <OTClientConnection.hpp>

#include <OTServer.hpp>

#include <OTAsymmetricKey.hpp>
#include <OTDataCheck.hpp>
#include <OTEnvelope.hpp>
#include <OTLog.hpp>
#include <OTMessage.hpp>
#include <OTPayload.hpp>

#include <cstdio>

extern "C"
{
#if defined (OPENTXS_HAVE_NETINET_IN_H)
#include <netinet/in.h>
#endif
}

void SetupHeader( union u_header * pCMD, int32_t nTypeID, int32_t nCmdID, OTPayload & thePayload)
{
	OT_ASSERT(NULL != pCMD);

	pCMD->fields.type_id	= (nTypeID > 0) ? static_cast<BYTE>(nTypeID) : '\0';
	pCMD->fields.command_id	= (nCmdID > 0) ? static_cast<BYTE>(nCmdID) : '\0';
  //	pCMD->fields.size		= thePayload.GetSize();
	pCMD->fields.size		= htonl(thePayload.GetSize()); // think this is causing problems
	pCMD->fields.checksum	= CalcChecksum(pCMD->buf, OT_CMD_HEADER_SIZE-1);

	BYTE byChecksum	= (BYTE)pCMD->fields.checksum;
	int32_t nChecksum	= byChecksum;

	uint32_t nTemp	= thePayload.GetSize();
	OTLog::vOutput(4, "(Payload size %d, TYPE %d command, checksum: %d...)\n", nTemp, nTypeID, nChecksum);
}

/*
  void OTClientConnection::ProcessBuffer()
  {
	int32_t  err, nread;
	union u_header theCMD;

	// clear the header object.
	memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);

	// Read the header
	for (nread = 0;  nread < OT_CMD_HEADER_SIZE;  nread += err)
	{
  err = SFSocketRead(m_pSocket,
  theCMD.buf + nread, OT_CMD_HEADER_SIZE - nread);
  if (err <= 0)
  {
  break;
  }
  else {
  OTLog::Output(2, "Reading input from socket...\n");
  }

	}

	if (nread)
	{
  OTLog::vOutput(4, "\n===> Processing header from client message. First 5 bytes are: %d %d %d %d %d...\n",
  theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4]);

  // When the server knows for SURE it is receiving a message,
  // then wait for 1 second to make sure we have the entire payload
  // at once.
  // TODO: rewrite socket code so that if a complete command has not yet
  // come in, to buffer the data and wait until next time around the loop.
  // Because right now, if you have a partial command, it reads it as an error
  // and returns, discarding what had already been read. Obviously that will
  // not work for a real server.
  // In the meantime, this sleep allows me to do testing by insuring that,
  // with a second's wait, the server will have time to read the entire message.
  sleep(1);

  ProcessMessage(theCMD);
	}
  }
*/

/*

  union u_header
  {
  BYTE buf[OT_CMD_HEADER_SIZE];

  struct
  {
  uint8_t type_id;    // 1 byte
  uint8_t command_id; // 1 byte
  BYTE filler[2];
  uint32_t size;     // 4 bytes to describe size of payload
  uint8_t  checksum;  // 1 byte

  } fields;  // total of 9 bytes
  }
*/

void OTClientConnection::ProcessBuffer()
{
	if (!m_bHaveHeader)
	{
		int32_t  err = 0, nread = 0;
		union u_header theCMD;

		// clear the header object.
		memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);

		// Read the header
		for (nread = 0;  nread < OT_CMD_HEADER_SIZE;  nread += err)
		{
      //			err = SFSocketRead(m_pSocket,
      //							   theCMD.buf + nread, OT_CMD_HEADER_SIZE - nread);

#ifdef _WIN32
			if (0 == err || SOCKET_ERROR == err) // 0 is a disconnect. error is error. otherwise err contains bytes read.
#else
        if (err <= 0)
#endif
        {
          break;
        }
        else {
          OTLog::Output(2, "Reading input from socket...\n");
        }
		}

		if (nread == OT_CMD_HEADER_SIZE)
		{
			uint32_t lOldSize	= theCMD.fields.size;
			uint32_t lSize		= ntohl(lOldSize); // think this might be causing some problems... maybe not.
			theCMD.fields.size	= lSize; // fix the byte order.

			m_CMD			= theCMD;	// grab a copy of the header
			m_bHaveHeader	= true;		// We need to remember that we are now in "header mode"

			int32_t nChecksum	= theCMD.fields.checksum;

			OTLog::vOutput(2, "\n************************************************************\n===> Reading header from client message.\n"
        "First 9 bytes are: %d %d %d %d %d %d %d %d %d.\nSize is: %d...\n",
        theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4],
        theCMD.buf[5], theCMD.buf[6], theCMD.buf[7], theCMD.buf[8], lSize);

			OTLog::vOutput(2, "\nCMD HEADER:   CMD TYPE: %d -- CMD NUM: %d\n"
        "PAYLOAD SIZE: %d -- CHECKSUM: %d\n", theCMD.fields.type_id,
        theCMD.fields.command_id, lSize, nChecksum);

			ReadBytesIntoBuffer();

			// When the server knows for SURE it is receiving a message,
			// then wait for 1 second to make sure we have the entire payload
			// at once.
			// TODO: rewrite socket code so that if a complete command has not yet
			// come in, to buffer the data and wait until next time around the loop.
			// Because right now, if you have a partial command, it reads it as an error
			// and returns, discarding what had already been read. Obviously that will
			// not work for a real server.
			// In the meantime, this sleep allows me to do testing by insuring that,
			// with a second's wait, the server will have time to read the entire message.
      //		sleep(1);

      //		ProcessMessage(theCMD);
		}
	}
	else {
		// If we've finally read enough into our buffer to process the entire mesage, then process it.
		if (m_Buffer.GetSize() >= m_CMD.fields.size)
		{
			ProcessMessage(m_CMD);
			m_bHaveHeader = false;
		} // otherwise if we haven't read enough, just read a bit more and wait until next time.
		else
			ReadBytesIntoBuffer();
	}
}

// We'll buffer 8K at a time for each user.
// It's smart enough not to read more data than required for the message payload.
// After that it would just start eating into the next header - so it stops.
void OTClientConnection::ReadBytesIntoBuffer()
{
	// At this point, the checksum has already validated.
	// Might as well get the PAYLOAD next.
	int32_t			err = 0;
	uint32_t	nread = 0;

	const uint32_t  nBufferSize = 8192; // todo no hardcoding.
	uint8_t       szBuffer[8300]; // I made this a little bigger just for safety reasons.

	memset(szBuffer, 0, 8299);  // just in case.

	//ultimately we want to read until m_Buffer.GetSize equals m_CMD.fields.size
	// In this function we'll read up to that or 8192, whichever is smaller.
	uint32_t	lNumberOfBytesRemaining	= m_CMD.fields.size - m_Buffer.GetSize();
	uint32_t	nNumberOfBytesToRead	= ((lNumberOfBytesRemaining > nBufferSize) ? nBufferSize : lNumberOfBytesRemaining);

	// actually read the payload from the socket into the buffer.
	for (nread = 0;  nread < nNumberOfBytesToRead;  nread += err)
	{
    //		err = SFSocketRead(m_pSocket,
    //						   szBuffer + nread,
    //						   nNumberOfBytesToRead - nread);

		// if we don't read anything more, stop reading and move on
#ifdef _WIN32
		if (0 == err || SOCKET_ERROR == err) // 0 means disconnect. error means error. >0 means bytes read.
#else
      if (err <= 0)
#endif
        break;
	}

	// If we read anything, up to 4K, we add it to the m_Buffer.
	// This continues happening until m_Buffer.GetSize() == m_CMD.fields.size
	// and then other code reads the message from the buffer and processes it.
	if (nread)
	{
		OTData toAddData(szBuffer, nread);
		m_Buffer += toAddData;
	}
}

// If a valid header is received, this function gets called.
// The job of this function is to creae the message, read it, and add it to m_listIn.
// ...and also, if there are unexpected bytes, to flush them in anticipation of the
// next valid message.
void OTClientConnection::ProcessMessage(u_header & theCMD)
{
	bool bSuccess = false;

	OTMessage * pMsg = NULL;

	if ( theCMD.fields.type_id == CMD_TYPE_1 )
	{
		OTLog::Output(2, "Received a Type 1 Command...\n");

		if( IsChecksumValid( theCMD.buf, OT_CMD_HEADER_SIZE ) )
		{
			OTLog::Output(2, "Checksum is valid! Processing payload.\n");

			pMsg = new OTMessage;

			if (ProcessType1Cmd(theCMD, *pMsg ))
			{
				AddToInputList(*pMsg);
				bSuccess = true;
			}
			else {
				delete pMsg;
				pMsg = NULL;
			}
		}
		else
		{
			//gDebugLog.Write("Invalid checksum - Type 1 Command");
			OTLog::vError("Invalid checksum - Type 1 Command, header size: %d\n", OT_CMD_HEADER_SIZE);
		}
	}
	else
	{
		//gDebugLog.Write("Unknown command type");
		int32_t nCommandType = theCMD.fields.type_id;
		OTLog::vError("Unknown command type: %d\n", nCommandType);
	}

	// I added this for error correction. In the event that there are errors,
	// just clean out whatever is in the pipe and throw it away.
	// Should probably send an Error message back, as well.
	if (bSuccess == false)
	{
		int32_t  err = 0, nread = 0;

		for(;;)
		{
      //			err = SFSocketRead(m_pSocket, buffer, sizeJunkData);

			if (err > 0)
				nread += err;

#ifdef _WIN32
			if (0 == err || SOCKET_ERROR == err) // 0 means disconnect. error means error. >0 means bytes read.
#else
        if (err <= 0)
#endif
          break;
		}

		OTLog::vError("Transmission error--%d bytes flushed.\n", nread);

		// we are buffering data from the pipe now, so if we flush the pipe, we
		// should flush the buffer too.
		m_Buffer.Release();
	}
	else
	{
		// TODO still need to process the commands and send the replies somewhere...
		//if (bSuccess = theServer.ProcessUserCommand(theMessage, theReply))
		//{
    //		OTLog::vOutput(4, "Successfully processed user command: %s\n", theMessage.m_strCommand.Get());
    //			ProcessReply(ssl, theReply);
    //		}
    //		else
    //		{
    //			OTLog::vError("Unable to process user command in XML, or missing payload, in ProcessMessage.\n");
    //		}
	}
}

// A certain number of bytes are expected in the payload, according to the header.
// This function tries to read that many bytes, and inserts them into an OTPayload object.
// From there, a simple method call extracts the message, we return true, and the message
// gets added to our internal list for processing.
bool OTClientConnection::ProcessType1Cmd(u_header & theCMD, OTMessage & theMessage)
{
	// At this point, the checksum has already validated.
	// Might as well get the PAYLOAD next.
  //	int32_t  err;
	uint32_t nread, lSize = theCMD.fields.size;

	// Make sure our byte-order is correct here.
  //	theCMD.fields.size = ntohl(theCMD.fields.size); // I was doing this twice!! This is already done when the header is first read.

	// setup the buffer we are reading into
	OTPayload thePayload;
	nread = thePayload.ReadBytesFrom(m_Buffer, lSize);

	/*
	// actually read the payload from the socket into the buffer.
	for (nread = 0;  nread < theCMD.fields.size;  nread += err)
	{
  err = SFSocketRead(m_pSocket,
  (uint8_t *)thePayload.GetPayloadPointer() + nread,
  theCMD.fields.size - nread);

  // if we don't read anything more, stop reading and move on
  if (err <= 0)
  break;
	}
	*/
	// TODO fix the buffering so that if a complete command has not yet been received, it saves the other
	// bytes instead of discarding them.  For now I'll just sleep for a second to make sure the entire command
	// was received.
  //	sleep(1);

	// ------------------------------------------------------------

	// Try to interpret the command number.
	// Right now we support signed messages and encrypted envelopes containing
	// signed messages.
	switch (theCMD.fields.command_id) {
		case TYPE_1_CMD_1:
			OTLog::Output(2, "Received Type 1 CMD 1:\nThere is a signed OTMessage in the payload.\n");
			break;
		case TYPE_1_CMD_2:
			OTLog::Output(2, "Received Type 1 CMD 2:\n"
        "There is an encrypted OTEnvelope (containing signed OTMessage) in the payload.\n");
			break;
		default:
			OTLog::vError("Received unexpected command number %d in OTClientConnection::ProcessType1Cmd\n",
        theCMD.fields.command_id);
			break;
	}

	// ------------------------------------------------------------
	// Hm, that's weird. It was a 0 size payload message. DoS?
	if (theCMD.fields.size == 0)
	{
		OTLog::Output(2, "(The payload was a 0 size.)\n");
		return true;
	}
	// Uh-oh, somehow the number of bytes read was less than what we expected...
	else if (nread < theCMD.fields.size)
	{
		// TODO: Verify that the amount read matched the amount expected
		// if not, we have a problem that needs to be handled.

		// Long term solution is to buffer the data as a comes in and just
		// add it to the buffer.

		// Then if we don't have the complete message yet, we just come around next
		// time some data is read, and we add that to the buffer, THEN we check to see
		// if there are enough bytes yet read to match the amount expected according to
		// the header.
		//
		// Until I can do that, I'm not yet TRULY asynchronous. TODO: lookup a good buffer class.

		OTLog::Error("Number of bytes read did NOT match size in header.\n");
		return false;
	}
	else
		OTLog::vOutput(2, "Loaded a payload, size: %d\n", theCMD.fields.size);

	// ------------------------------------------------------------

	// Okay so now we've received the expected size from the socket. Let's transfer it
	// into an object type that we can manipulate here in code. (Message or Envelope.)

	// a signed OTMessage
	if (TYPE_1_CMD_1 == theCMD.fields.command_id)
	{
		if (thePayload.GetMessagePayload(theMessage))
		{
			OTLog::Output(2, "Successfully retrieved payload message...\n");

			if (theMessage.ParseRawFile())
			{
				OTLog::Output(2, "Successfully parsed payload message.\n");

				return true;
			}
			else {
				OTLog::Error("Error parsing message.\n");
				return false;
			}

		}
		else {
			OTLog::Error("Error retrieving message from payload.\n");
			return false;
		}

	}

	// A base64-encoded envelope, encrypted, and containing a signed message.
	else if (TYPE_1_CMD_2 == theCMD.fields.command_id)
	{
		OTEnvelope theEnvelope;
		if (thePayload.GetEnvelope(theEnvelope))
		{
			OTLog::Output(2, "Successfully retrieved envelope from payload...\n");

			OTString strEnvelopeContents;

			// Decrypt the Envelope.
			if (m_pServer && theEnvelope.Open(m_pServer->GetServerNym(), strEnvelopeContents))
			{
				// All decrypted, now let's load the results into an OTMessage.
				// No need to call theMessage.ParseRawFile() after, since
				// LoadContractFromString handles it.
				//
				if (strEnvelopeContents.Exists() && theMessage.LoadContractFromString(strEnvelopeContents))
				{
					OTLog::Output(2, "Success loading message out of the envelope contents and parsing it.\n");
					return true;
				}
				else
				{
					OTLog::Error("Error loading message from envelope contents.\n");
					return false;
				}
			}
			else
			{
				OTLog::Error("Unable to open envelope.\n");
				return false;
			}
		}
		else
		{
			OTLog::Error("Error retrieving message from payload.\n");
			return false;
		}
	}

	return true;
}

// At certain times, when the server has verified that a Nym REALLY is who
// he says he is, he sets the public key onto the connection object for
// that nym.  That way, if the connection object ever needs to encrypt something
// being sent to the client, he has access to the public key.
void OTClientConnection::SetPublicKey(const OTString & strPublicKey)
{
  OT_ASSERT(NULL != m_pPublicKey);

	// SetPublicKey takes the ascii-encoded text, including bookends, and processes
	// it into the OTAssymeticKey object. If successful, the OTAssymetricKey is now
	// fully functional for encrypting and verifying.
	m_pPublicKey->SetPublicKey(strPublicKey, true/*bEscaped*/);
}

void OTClientConnection::SetPublicKey(const OTAsymmetricKey & thePublicKey)
{
  OT_ASSERT(NULL != m_pPublicKey);

	OTString strNymsPublicKey;

	thePublicKey. GetPublicKey(strNymsPublicKey, true);
	m_pPublicKey->SetPublicKey(strNymsPublicKey, true/*bEscaped*/);
}

// This function, you pass in a message and it returns true or false to let
// you know whether the message was successfully sealed into theEnvelope.
// (Based on the public key into cached in the OTClientConnection...)
// This is for XmlRpc / HTTP mode.
//
bool OTClientConnection::SealMessageForRecipient(OTMessage & theMsg, OTEnvelope & theEnvelope)
{
  OT_ASSERT(NULL != m_pPublicKey);

	if (!(m_pPublicKey->IsEmpty()) && m_pPublicKey->IsPublic())
	{
		// Save the ready-to-go message into a string.
		OTString strEnvelopeContents(theMsg);

		// Seal the string up into an encrypted Envelope.
		if (strEnvelopeContents.Exists())
			return theEnvelope.Seal(*m_pPublicKey, strEnvelopeContents);
	}
	else
		OTLog::Error("OTClientConnection::SealMessageForRecipient: "
      "Unable to seal message, possibly a missing public key. \n");
	return false;
}

void OTClientConnection::AddToInputList(OTMessage & theMessage)
{
	m_listIn.Push(theMessage);
}

OTMessage * OTClientConnection::GetNextInputMessage()
{
  OT_FAIL_MSG("OTClientConnection::GetNextInputMessage: ASSERT: Should not be calling this...");
}

void OTClientConnection::AddToOutputList(OTMessage & theMessage)
{
	m_listOut.Push(theMessage);

}

OTMessage * OTClientConnection::GetNextOutputMessage()
{
  OT_FAIL_MSG("OTClientConnection::GetNextOutputMessage: ASSERT: Should not be calling this...");
}

// For XmlRpc / HTTP mode.
OTClientConnection::OTClientConnection(OTServer & theServer)
  : m_pServer(&theServer), m_pPublicKey(OTAsymmetricKey::KeyFactory())
{
	m_bHaveHeader	= false;
	m_bFocused		= true; // rpc over http mode
}

OTClientConnection::~OTClientConnection()
{
  if (NULL != m_pPublicKey)
  {
    delete m_pPublicKey;
    m_pPublicKey = NULL;
  }
}
