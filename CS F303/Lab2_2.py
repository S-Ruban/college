sf = "senderFile.txt"
af = "receiverFile.txt"
print("Shared files created: 1) {0}, 2) {1}".format(sf, af))
seqBuf = [0, 1, 0, 1, 0]
bufr = ["1110", "1100", "1010", "1111", "010101"]


def sender(s, start):
    global seqBuf, bufr
    ack_num = ""
    frame = ""
    if start != 0:
        # open ack file
        fn2 = open(af, "r")
        lines = fn2.readlines()
        fn2.close()
        ########
        ln_count = len(lines)
        ln = lines[ln_count - 1]
        toks = ln.split()
        ack_str = toks[0]
        ack_number = int(toks[1])
        received_frame = "msg received: {0} {1}".format(ack_str, ack_num)
        print("Sender: ", received_frame)
        if ack_str == "ack":
            ack_num = ack_number
        else:
            pass
    else:
        ack_num = 0
        # print('Sender: ack_num = ', ack_num)
        if ack_num == s % 2:
            seq = seqBuf[s]
            msg = bufr[s]
            frame = "{0} {1}\n".format(seq, msg)
            # writing to msg file
            fn1 = open(sf, "a+")
            fn1.write(frame)
            fn1.close()
            ###########
            print("Sender: msg send: msg = {0}".format(msg))
        else:
            print("channel is not error free, msg or ack lost")


def receiver():
    global bufr
    # read msg file
    fn1 = open(sf, "r")
    lines = fn1.readlines()
    fn1.close()
    ###########
    ln_count = len(lines)
    ln = lines[ln_count - 1]
    toks = ln.split()
    received_frame = "msg: {0}".format(toks[1])
    print("Receiver: msg received: ", received_frame)
    seq = int(toks[0])
    ack = (seq + 1) % 2
    ############## prepare response
    response = "ack " + str(ack) + "\n"
    ## write to response file
    fn2 = open(af, "a+")
    fn2.write(response)
    fn2.close()
    ######
    print("Receiver: resp. sent: {0}".format(response))


if __name__ == "__main__":
    s = 0
    while True:
        if s == 0:
            sender(s, 0)
        else:
            sender(s, 1)
        ans_str = input("continue(y/n)?")
        ans = ans_str.rstrip()
        if ans == "y":
            receiver()
        else:
            break
        inp = input(
            "{0} frames sent; to stop, enter 'y', else enter 'n'".format((s + 1))
        )
        if s > 4:
            print("no more frames to send, exiting!!!")
            break
        if inp == "y":
            break
        else:
            s = s + 1
