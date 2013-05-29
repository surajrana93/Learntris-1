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
Date                   :=2013-05-28
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
ObjectsFileList        :="Learntris.txt"
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
CXXFLAGS :=  -g -O0 -Wall  -pedantic  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/GameBoard$(ObjectSuffix) $(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix) $(IntermediateDirectory)/Tetromino$(ObjectSuffix) $(IntermediateDirectory)/LearntrisTests$(ObjectSuffix) $(IntermediateDirectory)/TetrominoRotation$(ObjectSuffix) $(IntermediateDirectory)/TetrominoGravity$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
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
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/GameBoard$(ObjectSuffix): GameBoard.cpp $(IntermediateDirectory)/GameBoard$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameBoard$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameBoard$(DependSuffix): GameBoard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameBoard$(ObjectSuffix) -MF$(IntermediateDirectory)/GameBoard$(DependSuffix) -MM "GameBoard.cpp"

$(IntermediateDirectory)/GameBoard$(PreprocessSuffix): GameBoard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameBoard$(PreprocessSuffix) "GameBoard.cpp"

$(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix): GameBoardDiag.cpp $(IntermediateDirectory)/GameBoardDiag$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/GameBoardDiag.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameBoardDiag$(DependSuffix): GameBoardDiag.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameBoardDiag$(ObjectSuffix) -MF$(IntermediateDirectory)/GameBoardDiag$(DependSuffix) -MM "GameBoardDiag.cpp"

$(IntermediateDirectory)/GameBoardDiag$(PreprocessSuffix): GameBoardDiag.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameBoardDiag$(PreprocessSuffix) "GameBoardDiag.cpp"

$(IntermediateDirectory)/Tetromino$(ObjectSuffix): Tetromino.cpp $(IntermediateDirectory)/Tetromino$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/Tetromino.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tetromino$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tetromino$(DependSuffix): Tetromino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tetromino$(ObjectSuffix) -MF$(IntermediateDirectory)/Tetromino$(DependSuffix) -MM "Tetromino.cpp"

$(IntermediateDirectory)/Tetromino$(PreprocessSuffix): Tetromino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tetromino$(PreprocessSuffix) "Tetromino.cpp"

$(IntermediateDirectory)/LearntrisTests$(ObjectSuffix): LearntrisTests.cpp $(IntermediateDirectory)/LearntrisTests$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/LearntrisTests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LearntrisTests$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LearntrisTests$(DependSuffix): LearntrisTests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LearntrisTests$(ObjectSuffix) -MF$(IntermediateDirectory)/LearntrisTests$(DependSuffix) -MM "LearntrisTests.cpp"

$(IntermediateDirectory)/LearntrisTests$(PreprocessSuffix): LearntrisTests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LearntrisTests$(PreprocessSuffix) "LearntrisTests.cpp"

$(IntermediateDirectory)/TetrominoRotation$(ObjectSuffix): TetrominoRotation.cpp $(IntermediateDirectory)/TetrominoRotation$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/TetrominoRotation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TetrominoRotation$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TetrominoRotation$(DependSuffix): TetrominoRotation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TetrominoRotation$(ObjectSuffix) -MF$(IntermediateDirectory)/TetrominoRotation$(DependSuffix) -MM "TetrominoRotation.cpp"

$(IntermediateDirectory)/TetrominoRotation$(PreprocessSuffix): TetrominoRotation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TetrominoRotation$(PreprocessSuffix) "TetrominoRotation.cpp"

$(IntermediateDirectory)/TetrominoGravity$(ObjectSuffix): TetrominoGravity.cpp $(IntermediateDirectory)/TetrominoGravity$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/Chance/Dropbox/Code/LearntrisAgain/Learntris/TetrominoGravity.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TetrominoGravity$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TetrominoGravity$(DependSuffix): TetrominoGravity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TetrominoGravity$(ObjectSuffix) -MF$(IntermediateDirectory)/TetrominoGravity$(DependSuffix) -MM "TetrominoGravity.cpp"

$(IntermediateDirectory)/TetrominoGravity$(PreprocessSuffix): TetrominoGravity.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TetrominoGravity$(PreprocessSuffix) "TetrominoGravity.cpp"


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
	$(RM) $(IntermediateDirectory)/LearntrisTests$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/LearntrisTests$(DependSuffix)
	$(RM) $(IntermediateDirectory)/LearntrisTests$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/TetrominoRotation$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/TetrominoRotation$(DependSuffix)
	$(RM) $(IntermediateDirectory)/TetrominoRotation$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/TetrominoGravity$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/TetrominoGravity$(DependSuffix)
	$(RM) $(IntermediateDirectory)/TetrominoGravity$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/Learntris"


