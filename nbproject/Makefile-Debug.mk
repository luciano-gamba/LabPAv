#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/a0b48249/Integer.o \
	${OBJECTDIR}/_ext/a0b48249/String.o \
	${OBJECTDIR}/_ext/977bdecf/List.o \
	${OBJECTDIR}/_ext/977bdecf/ListIterator.o \
	${OBJECTDIR}/_ext/977bdecf/ListNode.o \
	${OBJECTDIR}/_ext/977bdecf/OrderedDictionary.o \
	${OBJECTDIR}/_ext/977bdecf/OrderedDictionaryEntry.o \
	${OBJECTDIR}/_ext/52371e0/ICollectible.o \
	${OBJECTDIR}/_ext/52371e0/ICollection.o \
	${OBJECTDIR}/_ext/52371e0/IDictionary.o \
	${OBJECTDIR}/_ext/52371e0/IIterator.o \
	${OBJECTDIR}/_ext/52371e0/IKey.o \
	${OBJECTDIR}/_ext/52371e0/OrderedKey.o \
	${OBJECTDIR}/CLIENTE.o \
	${OBJECTDIR}/COMENTARIO.o \
	${OBJECTDIR}/COMPRA.o \
	${OBJECTDIR}/CONTROLADOR.o \
	${OBJECTDIR}/DataDireccion.o \
	${OBJECTDIR}/DataProd.o \
	${OBJECTDIR}/DataProducto.o \
	${OBJECTDIR}/ICONTROLADOR.o \
	${OBJECTDIR}/PRODUCTO.o \
	${OBJECTDIR}/PROMOCION.o \
	${OBJECTDIR}/USUARIO.o \
	${OBJECTDIR}/VENDEDOR.o \
	${OBJECTDIR}/compra_producto.o \
	${OBJECTDIR}/date.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/promocion_producto.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utecmercadosuelto

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utecmercadosuelto: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utecmercadosuelto ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/a0b48249/Integer.o: ../../Escritorio/ICollection/Integer.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/a0b48249
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a0b48249/Integer.o ../../Escritorio/ICollection/Integer.cpp

${OBJECTDIR}/_ext/a0b48249/String.o: ../../Escritorio/ICollection/String.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/a0b48249
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a0b48249/String.o ../../Escritorio/ICollection/String.cpp

${OBJECTDIR}/_ext/977bdecf/List.o: ../../Escritorio/ICollection/collections/List.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/977bdecf
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/977bdecf/List.o ../../Escritorio/ICollection/collections/List.cpp

${OBJECTDIR}/_ext/977bdecf/ListIterator.o: ../../Escritorio/ICollection/collections/ListIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/977bdecf
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/977bdecf/ListIterator.o ../../Escritorio/ICollection/collections/ListIterator.cpp

${OBJECTDIR}/_ext/977bdecf/ListNode.o: ../../Escritorio/ICollection/collections/ListNode.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/977bdecf
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/977bdecf/ListNode.o ../../Escritorio/ICollection/collections/ListNode.cpp

${OBJECTDIR}/_ext/977bdecf/OrderedDictionary.o: ../../Escritorio/ICollection/collections/OrderedDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/977bdecf
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/977bdecf/OrderedDictionary.o ../../Escritorio/ICollection/collections/OrderedDictionary.cpp

${OBJECTDIR}/_ext/977bdecf/OrderedDictionaryEntry.o: ../../Escritorio/ICollection/collections/OrderedDictionaryEntry.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/977bdecf
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/977bdecf/OrderedDictionaryEntry.o ../../Escritorio/ICollection/collections/OrderedDictionaryEntry.cpp

${OBJECTDIR}/_ext/52371e0/ICollectible.o: ../../Escritorio/ICollection/interfaces/ICollectible.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52371e0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52371e0/ICollectible.o ../../Escritorio/ICollection/interfaces/ICollectible.cpp

${OBJECTDIR}/_ext/52371e0/ICollection.o: ../../Escritorio/ICollection/interfaces/ICollection.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52371e0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52371e0/ICollection.o ../../Escritorio/ICollection/interfaces/ICollection.cpp

${OBJECTDIR}/_ext/52371e0/IDictionary.o: ../../Escritorio/ICollection/interfaces/IDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52371e0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52371e0/IDictionary.o ../../Escritorio/ICollection/interfaces/IDictionary.cpp

${OBJECTDIR}/_ext/52371e0/IIterator.o: ../../Escritorio/ICollection/interfaces/IIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52371e0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52371e0/IIterator.o ../../Escritorio/ICollection/interfaces/IIterator.cpp

${OBJECTDIR}/_ext/52371e0/IKey.o: ../../Escritorio/ICollection/interfaces/IKey.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52371e0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52371e0/IKey.o ../../Escritorio/ICollection/interfaces/IKey.cpp

${OBJECTDIR}/_ext/52371e0/OrderedKey.o: ../../Escritorio/ICollection/interfaces/OrderedKey.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52371e0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52371e0/OrderedKey.o ../../Escritorio/ICollection/interfaces/OrderedKey.cpp

${OBJECTDIR}/CLIENTE.o: CLIENTE.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CLIENTE.o CLIENTE.cpp

${OBJECTDIR}/COMENTARIO.o: COMENTARIO.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/COMENTARIO.o COMENTARIO.cpp

${OBJECTDIR}/COMPRA.o: COMPRA.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/COMPRA.o COMPRA.cpp

${OBJECTDIR}/CONTROLADOR.o: CONTROLADOR.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CONTROLADOR.o CONTROLADOR.cpp

${OBJECTDIR}/DataDireccion.o: DataDireccion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataDireccion.o DataDireccion.cpp

${OBJECTDIR}/DataProd.o: DataProd.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataProd.o DataProd.cpp

${OBJECTDIR}/DataProducto.o: DataProducto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataProducto.o DataProducto.cpp

${OBJECTDIR}/ICONTROLADOR.o: ICONTROLADOR.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICONTROLADOR.o ICONTROLADOR.cpp

${OBJECTDIR}/PRODUCTO.o: PRODUCTO.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PRODUCTO.o PRODUCTO.cpp

${OBJECTDIR}/PROMOCION.o: PROMOCION.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PROMOCION.o PROMOCION.cpp

${OBJECTDIR}/USUARIO.o: USUARIO.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/USUARIO.o USUARIO.cpp

${OBJECTDIR}/VENDEDOR.o: VENDEDOR.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VENDEDOR.o VENDEDOR.cpp

${OBJECTDIR}/compra_producto.o: compra_producto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/compra_producto.o compra_producto.cpp

${OBJECTDIR}/date.o: date.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/date.o date.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/promocion_producto.o: promocion_producto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/promocion_producto.o promocion_producto.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
