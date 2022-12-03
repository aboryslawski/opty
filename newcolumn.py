f = open("final_results.csv")
fc = f.readlines()
counter = 0
final_list = []
for x in fc:
    if counter == 0:
        counter = counter + 1
        final_list.append(x.strip() + ";minimum_lokalne_przez_globalne")
        continue
    if float(x.split(';')[5]) < 60:
        final_list.append(x.strip() + ";" + "lokalne")
    else:
        final_list.append(x.strip() + ";" + "globalne")
for x in final_list:
    print(x)
