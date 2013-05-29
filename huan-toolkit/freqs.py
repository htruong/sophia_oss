with open('out_freqs.txt') as infile:
  with open('out_freqs.xml', 'w') as outfile:
    outfile.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n")
    outfile.write("<wordlist locale=\"vi\" description=\"Vietnamese\" version=\"1\">\n")
    biggest = -1
    linenum = 1
    for line in infile:
      if line == "":
        continue
      fields = line.rstrip().split(' ')
      wfreq = int(fields[1])
      print("working on line ", linenum)
      linenum = linenum + 1
      if (biggest == -1):
        biggest = int(fields[1])
      if wfreq > 20:
        outfile.write("<w f=\"" + str(wfreq*254/biggest+1) + "\">" + fields[0] + "</w>\n")
      else:
        break
    outfile.write("</wordlist>")
