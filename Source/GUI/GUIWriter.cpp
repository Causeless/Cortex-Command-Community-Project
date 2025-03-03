#include "GUIWriter.h"

using namespace RTE;

void GUIWriter::Clear() {
	m_Stream = nullptr;
	m_FilePath.clear();
	m_FolderPath.clear();
	m_FileName.clear();
	m_IndentCount = 0;
}

GUIWriter::GUIWriter() {
	Clear();
}

int GUIWriter::Create(const std::string& fileName, bool append) {
	m_FilePath = fileName;

	// Extract filename and folder path
	size_t slashPos = m_FilePath.find_last_of("/\\");
	m_FileName = m_FilePath.substr(slashPos + 1);
	m_FolderPath = m_FilePath.substr(0, slashPos + 1);

	m_Stream = std::make_unique<std::ofstream>(fileName, append ? (std::ios::out | std::ios::app | std::ios::ate) : (std::ios::out | std::ios::trunc));

	if (!m_Stream->good()) {
		return -1;
	}
	return 0;
}

std::string GUIWriter::GetFilePath() const {
	return m_FilePath;
}

std::string GUIWriter::GetFileName() const {
	return m_FileName;
}

std::string GUIWriter::GetFolderPath() const {
	return m_FolderPath;
}

void GUIWriter::ObjectStart(const std::string& className) {
	*m_Stream << className;
	++m_IndentCount;
}

void GUIWriter::ObjectEnd() {
	--m_IndentCount;
	if (m_IndentCount == 0) {
		NewLine(false, 2);
	}
}

void GUIWriter::NewLine(bool toIndent, int lineCount) const {
	for (int lines = 0; lines < lineCount; ++lines) {
		*m_Stream << "\n";
		if (toIndent) {
			*m_Stream << std::string(m_IndentCount, '\t');
		}
	}
}

void GUIWriter::NewLineString(const std::string& textString, bool toIndent) const {
	NewLine(toIndent);
	*m_Stream << textString;
}

void GUIWriter::NewDivider(bool toIndent, int dividerLength) const {
	NewLine(toIndent);
	*m_Stream << std::string(dividerLength, '/');
}

void GUIWriter::NewProperty(const std::string& propName) const {
	NewLine();
	*m_Stream << propName + " = ";
}

bool GUIWriter::WriterOK() const {
	return m_Stream.get() && !m_Stream->fail() && m_Stream->is_open();
}

void GUIWriter::EndWrite() const {
	m_Stream->flush();
	m_Stream->close();
}

GUIWriter& GUIWriter::operator<<(const bool& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const char& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const unsigned char& var) {
	int temp = var;
	*m_Stream << temp;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const short& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const unsigned short& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const int& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const unsigned int& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const long& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const long long& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const unsigned long& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const unsigned long long& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const float& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const double& var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const char* var) {
	*m_Stream << var;
	return *this;
}

GUIWriter& GUIWriter::operator<<(const std::string& var) {
	*m_Stream << var;
	return *this;
}
