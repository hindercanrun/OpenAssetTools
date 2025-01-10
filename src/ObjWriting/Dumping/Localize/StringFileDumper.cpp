#include "StringFileDumper.h"

#include "Utils/StringUtils.h"

#include <regex>

StringFileDumper::StringFileDumper(Zone* zone, std::ostream& stream)
    : AbstractTextDumper(stream),
      m_zone(zone),
      m_language_caps("ENGLISH"),
      m_wrote_header(false)
{
}

void StringFileDumper::SetLanguageName(std::string language)
{
    m_language_caps = std::move(language);
    for (auto& c : m_language_caps)
        c = toupper(c);
}

void StringFileDumper::SetConfigFile(std::string configFile)
{
    m_config_file = std::move(configFile);
}

void StringFileDumper::SetNotes(std::string notes)
{
    m_notes = std::move(notes);
}

void StringFileDumper::WriteHeader()
{
    m_stream << "// Dumped from Fast File: \"" << m_zone->m_name << "\".\n";
    m_stream << "// In their original format the strings might have been separated in multiple files.\n";
    m_stream << "//\n";
    m_stream << "//\n";
    m_stream << "// Note to translators:\n";
    m_stream << "// If a sentence is the same in your language then please change it to \"#same\"\n";
    m_stream << "//\n";
    m_stream << "// eg:\n";
    m_stream << "// LANG_ENGLISH  \"HALT\"\n";
    m_stream << "// LANG_GERMAN   \"#same\"\n";
    m_stream << "//\n";
    m_stream << "// (This is so we can tell which strings have been signed-off as ok to be the same words for QA\n";
    m_stream << "//  and because we do not store duplicate strings, which will then get exported again next time\n";
    m_stream << "//  as being untranslated.)\n";
    m_stream << "//\n";
    m_stream << "VERSION             \"1\"\n"; // all strings seem to be "1"
    m_stream << "CONFIG              \"" << m_config_file << "\"\n";
    m_stream << "FILENOTES           \"" << m_notes << "\"\n";

    m_wrote_header = true;
}

void StringFileDumper::WriteReference(const std::string& reference) const
{
    if (reference.find_first_not_of(utils::LETTERS_AL_NUM_UNDERSCORE) != std::string::npos)
    {
        m_stream << "REFERENCE           \"";

        utils::EscapeStringForQuotationMarks(m_stream, reference);

        m_stream << "\"\n";
    }
    else
    {
        m_stream << "REFERENCE           " << reference << "\n";
    }
}

void StringFileDumper::WriteLocalizeEntry(const std::string& reference, const std::string& value)
{
    if (!m_wrote_header)
    {
        WriteHeader();
    }

    m_stream << "\n";
    WriteReference(reference);

    const auto valueSpacing = std::string(15 - m_language_caps.length(), ' ');
    m_stream << "LANG_" << m_language_caps << valueSpacing << "\"";
    utils::EscapeStringForQuotationMarks(m_stream, value);
    m_stream << "\"\n";
}

void StringFileDumper::Finalize()
{
    if (!m_wrote_header)
    {
        WriteHeader();
    }

    m_stream << "\nENDMARKER\n";
}
