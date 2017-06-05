#
# This script is to create new LeetCode project
#
import os;
import shutil
import re;
projRoot = r"C:\Users\richli\Source\Repos\LeetCode\MyTests"
print projRoot

tempProj = "MaxPrefix"
newProj  = "ThreeSum"


##
# copy from src to dst
srcPath = projRoot + "\\" + tempProj + "\\"
dstPath = projRoot + "\\" + newProj 
#os.remove(dstPath)
if (os.path.exists(dstPath)):
    os.system( "rmdir /S /Q " + dstPath)
os.mkdir(dstPath);

files = ["input.txt", "Source.cpp",  tempProj + ".vcxproj.filters"]

for file in files:
    src = srcPath + file
    dst = dstPath + "\\" + file.replace(tempProj, newProj)
    print "copy from %s to %s " % (src, dst)
    shutil.copyfile(src, dst)


###
# for vcxproj
name = "MaxPrefix.vcxproj"
vcxproj  = open(projRoot + "\\" + tempProj + "\\" + name).read()
vcxproj = vcxproj.replace(tempProj, newProj)
fp = open(dstPath + "\\" + name.replace(tempProj, newProj), "w")
fp.write(vcxproj);
fp.close()


# Update 
fp = open(projRoot + "\\MyTests.sln", "r")

dstCnt = "";
tempId = ""
newId = ""
newConfigs = ""
for line in fp.readlines():
    
    if (line.find(tempProj) != -1):
        newLine = line.replace(tempProj, newProj)
        searchObj = re.search(r'-([A-F0-9]*)}"$', newLine)
        if searchObj:
            tempId = searchObj.group(1)
            newId = "%012X" % (int(tempId, 16) + 1)
        else:
            assert(0)
        dstCnt += newLine.replace(tempId, newId)
        dstCnt += "EndProject\n"

    if (line.find(tempId) != -1) and  ((line.find("Debug") != -1) or (line.find("Release") != -1)):
         newConfigs += line
    
    if (line.find("EndGlobalSection") != -1) and (newConfigs != ""):
        dstCnt += newConfigs.replace(tempId, newId)
        newConfigs = "";
    dstCnt += line

fp = open(projRoot + "\\MyTests.sln", "w")

fp.write(dstCnt)
fp.close()