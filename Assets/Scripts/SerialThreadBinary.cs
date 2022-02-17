using UnityEngine;
using System.IO.Ports;

public class SerialThreadBinary : AbstractSerialThread
{
    private byte[] buffer = new byte[8];

    public SerialThreadBinary(string portName,
                                       int baudRate,
                                       int delayBeforeReconnecting,
                                       int maxUnreadMessages,
                                       bool dropOldMessage)
        : base(portName, baudRate, delayBeforeReconnecting, maxUnreadMessages, false, dropOldMessage)
    {

    }

    protected override void SendToWire(object message, SerialPort serialPort)
    {
        byte[] binaryMessage = (byte[])message;
        serialPort.Write(binaryMessage, 0, binaryMessage.Length);
    }

    protected override object ReadFromWire(SerialPort serialPort)
    {
        if (serialPort.BytesToRead > 0)
        {
            serialPort.Read(buffer, 0, 1);
            byte[] returnBuffer = new byte[1];
            System.Array.Copy(buffer, returnBuffer, 1);
            return returnBuffer;
        }
        else
        {
            return null;
        }
    }
}
