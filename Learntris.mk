##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Learntris
ConfigurationName      :=Debug
WorkspacePath          := "/Users/Chance/Dropbox/Code/LearntrisAgain"
ProjectPath            := "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chance Rosenthal
Date                   :=2013-04-02
CodeLitePath           :="/Users/Chance/Library/Application Support/codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/Learntris.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/Applications/CodeLite.app/Contents/SharedSupport/
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/GameBoard$(ObjectSuffix) $(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix) $(IntermediateDirectory)/Tetromino$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/main.cpp"

$(IntermediateDirectory)/GameBoard$(ObjectSuffix): GameBoard.cpp $(IntermediateDirectory)/GameBoard$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameBoard$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameBoard$(DependSuffix): GameBoard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameBoard$(ObjectSuffix) -MF$(IntermediateDirectory)/GameBoard$(DependSuffix) -MM "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoard.cpp"

$(IntermediateDirectory)/GameBoard$(PreprocessSuffix): GameBoard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameBoard$(PreprocessSuffix) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoard.cpp"

$(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix): GameBoardDiag.cpp $(IntermediateDirectory)/GameBoardDiag$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoardDiag.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameBoardDiag$(DependSuffix): GameBoardDiag.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix) -MF$(IntermediateDirectory)/GameBoardDiag$(DependSuffix) -MM "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoardDiag.cpp"

$(IntermediateDirectory)/GameBoardDiag$(PreprocessSuffix): GameBoardDiag.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameBoardDiag$(PreprocessSuffix) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoardDiag.cpp"

$(IntermediateDirectory)/Tetromino$(ObjectSuffix): Tetromino.cpp $(IntermediateDirectory)/Tetromino$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/Tetromino.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tetromino$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tetromino$(DependSuffix): Tetromino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tetromino$(ObjectSuffix) -MF$(IntermediateDirectory)/Tetromino$(DependSuffix) -MM "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/Tetromino.cpp"

$(IntermediateDirectory)/Tetromino$(PreprocessSuffix): Tetromino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tetromino$(PreprocessSuffix) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/Tetromino.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/GameBoard$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/GameBoard$(DependSuffix)
	$(RM) $(IntermediateDirectory)/GameBoard$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/GameBoardDiag$(DependSuffix)
	$(RM) $(IntermediateDirectory)/GameBoardDiag$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Tetromino$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Tetromino$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Tetromino$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "/Users/Chance/Dropbox/Code/LearntrisAgain/.build-debug/Learntris"


